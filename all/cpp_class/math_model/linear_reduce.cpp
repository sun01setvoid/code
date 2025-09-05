#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

// 计算皮尔逊相关系数
double pearsonCorrelation(const vector<double>& x, const vector<double>& y) {
    if (x.size() != y.size()) return 0.0;

    int n = x.size();
    double sumX = 0, sumY = 0, sumXY = 0;
    double sumX2 = 0, sumY2 = 0;

    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    double numerator = n * sumXY - sumX * sumY;
    double denominator = sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY));
    if (denominator == 0) return 0.0;

    return numerator / denominator;
}

int main() {
    string filename = "data.xlsx"; // 你可以改为实际文件名
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "无法打开文件 " << filename << endl;
        return 1;
    }

    vector<double> speed, height, rpm, noise;
    string line;
    getline(file, line); // 跳过标题行

    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        double s, h, r, n;

        getline(ss, value, ','); s = stod(value);
        getline(ss, value, ','); h = stod(value);
        getline(ss, value, ','); r = stod(value);
        getline(ss, value, ','); n = stod(value);

        speed.push_back(s);
        height.push_back(h);
        rpm.push_back(r);
        noise.push_back(n);
    }

    file.close();

    // 计算并输出相关系数
    cout << fixed << setprecision(4);
    cout << "Speed - Noise 相关系数:  " << pearsonCorrelation(speed, noise) << endl;
    cout << "Height - Noise 相关系数: " << pearsonCorrelation(height, noise) << endl;
    cout << "RPM - Noise 相关系数:    " << pearsonCorrelation(rpm, noise) << endl;

    return 0;
}
