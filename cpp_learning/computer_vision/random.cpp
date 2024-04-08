#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int main() {
    int n = 10; // 生成n个不重复的整数
    int minRange = 1; // 最小范围
    int maxRange = 100; // 最大范围

    // 创建一个存储整数的容器
    std::vector<int> randomNumbers;

    // 填充容器，从最小范围到最大范围
    for (int i = minRange; i <= maxRange; ++i) {
        randomNumbers.push_back(i);
    }

    // 使用随机数引擎打乱容器中的元素
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(randomNumbers.begin(), randomNumbers.end(), rng);

    // 只选择前n个不重复的整数
    randomNumbers.resize(n);

    // 打印生成的不重复整数
    for (int number : randomNumbers) {
        std::cout << number << " ";
    }

    return 0;
}