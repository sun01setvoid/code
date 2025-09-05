#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

// 函数声明
void read_data(const string &filename, vector<vector<double>> &X, vector<double> &y);
void normalize(vector<vector<double>> &X);
vector<double> gradient_descent(const vector<vector<double>> &X, const vector<double> &y, double alpha, int iterations);
void output_results(const vector<double> &theta);
double predict(const vector<double> &theta, const vector<double> &features);

// 从文件中读取数据，并填充特征矩阵X和目标向量y
void read_data(const string &filename, vector<vector<double>> &X, vector<double> &y)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "文件无法打开: " << filename << endl;
        exit(1);
    }

    string line;
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        vector<double> row;
        double value;
        row.push_back(1.0);
        while (ss >> value)
        {
            row.push_back(value);
            if (ss.peek() == ' ')
                ss.ignore();
        }
        if (row.size() > 0)
        {
            y.push_back(row.back()); // 最后一个元素为房价
            row.pop_back();          // 移除房价值
            X.push_back(row);        // 特征部分添加到X
        }
        else
        {
            cerr << "读取的行为空或格式错误: " << line << endl;
        }
    }
}

// 归一化特征矩阵X
void normalize(vector<vector<double>> &X)
{
    for (size_t j = 1; j < X[0].size(); ++j)
    {
        double min_val = X[0][j];
        double max_val = X[0][j];

        for (const auto &row : X)
        {
            if (row[j] < min_val)
                min_val = row[j];
            if (row[j] > max_val)
                max_val = row[j];
        }

        for (auto &row : X)
        {
            row[j] = (row[j] - min_val) / (max_val - min_val);
        }
    }
}

// 使用梯度下降法计算模型参数theta
vector<double> gradient_descent(const vector<vector<double>> &X, const vector<double> &y, double alpha, int iterations)
{
    size_t m = y.size();
    vector<double> theta(X[0].size(), 1.0); // 初始化模型参数，包含偏置项
    for (int it = 0; it < iterations; ++it)
    {
        vector<double> gradients(theta.size(), 0.0);
        for (size_t i = 0; i < m; ++i)
        {
            double prediction = 0.0;
            for (size_t j = 0; j < X[i].size(); ++j)
            {
                prediction += theta[j] * X[i][j];
            }
            double error = prediction - y[i];
            for (size_t j = 0; j < X[i].size(); ++j)
            {
                gradients[j] += error * X[i][j];
            }
        }
        for (size_t j = 0; j < theta.size(); ++j)
        {
            theta[j] -= alpha / m * gradients[j];
        }
    }
    return theta;
}

// 输出模型参数
void output_results(const vector<double> &theta)
{
    cout << "模型参数：";
    for (const auto &t : theta)
    {
        cout << t << " ";
    }
    cout << endl;
}

// 根据特征计算预测值
double predict(const vector<double> &theta, const vector<double> &features)
{
    double prediction = theta[0];
    for (size_t j = 1; j < features.size(); ++j)
    {
        prediction += theta[j] * features[j];
    }
    return prediction;
}

// 主函数
int main()
{
    vector<vector<double>> X; // 特征矩阵
    vector<double> y;         // 目标向量（房价）

    cout << "开始读取数据..." << endl;
    // 从文件读取数据
    read_data("housing-price.txt", X, y);
    cout << "数据读取完成，归一化数据..." << endl;
    normalize(X); // 归一化特征数据

    double alpha = 0.01;    // 学习率
    int iterations = 100000; // 迭代次数
    cout << "开始梯度下降..." << endl;
    vector<double> theta = gradient_descent(X, y, alpha, iterations); // 进行梯度下降
    output_results(theta);                                            // 输出模型参数

    // 输入特征以进行预测
    cout << endl;
    cout << "请输入特征值（用空格分隔）：";
    vector<double> input_features(X[0].size());
    for (size_t i = 1; i < input_features.size(); ++i)
    {
        cin >> input_features[i];
    }

    // 进行房价预测
    double predicted_price = predict(theta, input_features);
    cout << "预测的房价为: " << predicted_price << endl;

    return 0;
}