#include <iostream>
#include <vector>

// 计算二介倒数（二阶导数）使用五点差分
std::vector<double> secondDerivative(const std::vector<double>& values, double h) {
    std::vector<double> result;
    int n = values.size();

    for (int i = 0; i < n; ++i) {
        if (i < 2 || i >= n - 2) {
            result.push_back(0.0); // 二介倒数在边界处为零
        } else {
            result.push_back((-values[i + 2] + 16 * values[i + 1] - 30 * values[i] + 16 * values[i - 1] - values[i - 2]) / (12 * h * h));
        }
    }

    return result;
}

int main() {
    // 输入离散点数据
    std::vector<double> data = {7.0, 5.4, 3.7, 2.7, 2.3 ,2.0 ,2.15 ,2.4 ,2.6,2.7,2.9};
    double h = 1.0; // 步长

    // 计算二介倒数
    std::vector<double> secondDeriv = secondDerivative(data, h);

    // 寻找二介倒数的最大值和最小值以及它们的索引
    double maxSecondDeriv = secondDeriv[0];
    double minSecondDeriv = secondDeriv[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < secondDeriv.size(); ++i) {
        if (secondDeriv[i] > maxSecondDeriv) {
            maxSecondDeriv = secondDeriv[i];
            maxIndex = i;
        }
        if (secondDeriv[i] < minSecondDeriv) {
            minSecondDeriv = secondDeriv[i];
            minIndex = i;
        }
    }

    // 输出结果
    std::cout << "二介倒数的最大值: " << maxSecondDeriv << "，位于索引 " << maxIndex << std::endl;
    std::cout << "二介倒数的最小值: " << minSecondDeriv << "，位于索引 " << minIndex << std::endl;

    return 0;
}
