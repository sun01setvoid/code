#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <random>
#include <limits>
#include <algorithm>
#include <map>
using namespace std;
struct DataPoint {
    vector<double> features;
    int cluster;
    DataPoint() : cluster(-1) {}
};

// 改进的数据加载函数
vector<DataPoint> loadIrisData(const string& filename) {
    vector<DataPoint> data;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        // 跳过空行
        if (line.empty()) continue;

        stringstream ss(line);
        string value;
        DataPoint dp;
        bool valid = true;

        // 读取前4个特征值
        for (int i = 0; i < 4; ++i) {
            if (!getline(ss, value, ',')) {
                valid = false;
                break;
            }

            try {
                dp.features.push_back(stod(value));
            } catch (const invalid_argument& e) {
                valid = false;
                break;
            }
        }

        if (valid && dp.features.size() == 4) {
            data.push_back(dp);
        }
    }
    return data;
}

// 数据标准化（Z-score归一化）
void normalizeData(vector<DataPoint>& data) {
    size_t num_features = data[0].features.size();
    size_t n = data.size();
    
    vector<double> means(num_features, 0.0);
    vector<double> stddevs(num_features, 0.0);

    // 计算均值
    for (const auto& dp : data) {
        for (size_t i = 0; i < num_features; ++i) {
            means[i] += dp.features[i];
        }
    }
    for (auto& mean : means) mean /= n;

    // 计算标准差
    for (const auto& dp : data) {
        for (size_t i = 0; i < num_features; ++i) {
            stddevs[i] += pow(dp.features[i] - means[i], 2);
        }
    }
    for (auto& stddev : stddevs) stddev = sqrt(stddev / n);

    // 归一化处理
    for (auto& dp : data) {
        for (size_t i = 0; i < num_features; ++i) {
            dp.features[i] = (dp.features[i] - means[i]) / stddevs[i];
        }
    }
}

// 初始化质心
vector<DataPoint> initializeCentroids(const vector<DataPoint>& data, int K) {
    vector<DataPoint> centroids;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, data.size()-1);

    for (int i = 0; i < K; ++i) {
        centroids.push_back(data[dis(gen)]);
    }
    return centroids;
}

// 计算欧氏距离
double euclideanDistance(const DataPoint& a, const DataPoint& b) {
    double sum = 0.0;
    for (size_t i = 0; i < a.features.size(); ++i) {
        sum += pow(a.features[i] - b.features[i], 2);
    }
    return sqrt(sum);
}

// 分配簇
void assignClusters(vector<DataPoint>& data, const vector<DataPoint>& centroids) {
    for (auto& dp : data) {
        double min_dist = numeric_limits<double>::max();
        for (size_t i = 0; i < centroids.size(); ++i) {
            double dist = euclideanDistance(dp, centroids[i]);
            if (dist < min_dist) {
                min_dist = dist;
                dp.cluster = i;
            }
        }
    }
}

// 更新质心
bool updateCentroids(vector<DataPoint>& centroids, const vector<DataPoint>& data) {
    bool changed = false;
    size_t K = centroids.size();
    size_t num_features = centroids[0].features.size();

    vector<vector<double>> sums(K, vector<double>(num_features, 0.0));
    vector<int> counts(K, 0);

    // 计算簇内和
    for (const auto& dp : data) {
        int cluster = dp.cluster;
        for (size_t j = 0; j < num_features; ++j) {
            sums[cluster][j] += dp.features[j];
        }
        counts[cluster]++;
    }

    // 更新质心
    for (size_t i = 0; i < K; ++i) {
        if (counts[i] == 0) continue;

        DataPoint new_centroid;
        new_centroid.features.resize(num_features);
        for (size_t j = 0; j < num_features; ++j) {
            new_centroid.features[j] = sums[i][j] / counts[i];
        }

        if (euclideanDistance(new_centroid, centroids[i]) > 1e-6) {
            centroids[i] = new_centroid;
            changed = true;
        }
    }
    return changed;
}

// 计算轮廓系数
double computeSilhouette(const vector<DataPoint>& data) {
    size_t n = data.size();
    if (n == 0) return -1.0;

    // 统计每个簇的数据点索引
    map<int, vector<size_t>> cluster_indices;
    for (size_t i = 0; i < data.size(); ++i) {
        cluster_indices[data[i].cluster].push_back(i);
    }

    double total_silhouette = 0.0;

    for (size_t i = 0; i < n; ++i) {
        int current_cluster = data[i].cluster;
        
        // 计算a(i): 同一簇内所有点的平均距离
        double a_i = 0.0;
        const auto& same_cluster_indices = cluster_indices[current_cluster];
        if (same_cluster_indices.size() <= 1) {
            total_silhouette += 0.0;
            continue;
        }
        
        for (size_t j : same_cluster_indices) {
            if (j != i) {
                a_i += euclideanDistance(data[i], data[j]);
            }
        }
        a_i /= (same_cluster_indices.size() - 1);

        // 计算b(i): 到其他簇的最小平均距离
        double min_avg_dist = numeric_limits<double>::max();
        for (const auto& pair : cluster_indices) {
            if (pair.first == current_cluster) continue;
            
            double avg_dist = 0.0;
            for (size_t j : pair.second) {
                avg_dist += euclideanDistance(data[i], data[j]);
            }
            avg_dist /= pair.second.size();
            
            if (avg_dist < min_avg_dist) {
                min_avg_dist = avg_dist;
            }
        }
        double b_i = min_avg_dist;

        // 计算当前点的轮廓系数
        double s_i = (b_i - a_i) / max(a_i, b_i);
        total_silhouette += s_i;
    }

    return total_silhouette / n;
}

int main() {
    const int K = 3;
    const int MAX_ITER = 100;

    // 加载和预处理数据
    vector<DataPoint> data = loadIrisData("data.txt");
    if (data.empty()) {
        cerr << "Error: No valid data loaded." << endl;
        return 1;
    }

    normalizeData(data);

    // 初始化质心
    vector<DataPoint> centroids = initializeCentroids(data, K);

    // K-Means主循环
    int iteration = 0;
    bool centroids_changed;
    do {
        assignClusters(data, centroids);
        centroids_changed = updateCentroids(centroids, data);
        
        // 每次迭代后计算轮廓系数
        double silhouette = computeSilhouette(data);
        cout << "Iteration " << iteration 
                  << ", Silhouette Score: " << silhouette << endl;
        
        iteration++;
    } while (centroids_changed && iteration < MAX_ITER);

    // 输出最终结果
    cout << "\nFinal results after " << iteration << " iterations:\n";
    
    // 输出每个簇的大小
    map<int, int> cluster_counts;
    for (const auto& dp : data) {
        cluster_counts[dp.cluster]++;
    }
    for (const auto& pair : cluster_counts) {
        cout << "Cluster " << pair.first << " size: " << pair.second << endl;
    }

    // 输出最终轮廓系数
    double final_silhouette = computeSilhouette(data);
    cout << "Final Silhouette Score: " << final_silhouette << endl;

    // 输出质心坐标
    cout << "\nFinal centroids:\n";
    for (size_t i = 0; i < centroids.size(); ++i) {
        cout << "Cluster " << i << ": [";
        for (double val : centroids[i].features) {
            cout << val << " ";
        }
        cout << "\b]\n";
    }

    return 0;
}