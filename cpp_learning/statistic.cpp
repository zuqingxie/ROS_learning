#include <iostream>
#include<Eigen/Dense>
using namespace std;
using namespace Eigen;
#include <random> // C++标准库中的随机数生成器

// g++ filename -o runable_name;
// ./runable_name
#if 0
int main()
{
    // 数据集，假设有3个数据点，每个数据点有2维
    Eigen::MatrixXd dataset(1, 8);
    dataset << 1.0, 2.0, 3.0,2,4,3,1,4;
            //    4.0, 5.0, 6.0,1,2,3,4,4,
            //    7.0, 1.0, 6.0,1,2,3,4,4;

    // 计算均值
    Eigen::VectorXd mean = dataset.rowwise().mean();

    // 计算协方差
    Eigen::MatrixXd centered = dataset.colwise() - mean;
    Eigen::MatrixXd covariance = (centered * centered.transpose()) / static_cast<double>(dataset.cols() - 1);

    // 输出结果
    std::cout << "Mean:\n" << mean << std::endl;
    std::cout << "Covariance:\n" << covariance << std::endl;

    return 0;
}
#endif

#if 1


int main()
{
    // 二维数据集
    // Eigen::MatrixXd dataset(2, 10000);
    // // 假设数据集为随机生成的
    // dataset = Eigen::MatrixXd::Random(2, 10000);


    // 创建一个随机数生成器
    const int num_dimensions = 2;
    const int num_data_points = 10000;

    std::default_random_engine rng;
    std::normal_distribution<double> normal_dist(0.0, 1.0); // 均值为0，方差为1的正态分布

    // 创建一个Eigen MatrixXd来存储数据集
    Eigen::MatrixXd dataset(num_dimensions, num_data_points);

    // 填充数据集
    for (int i = 0; i < num_data_points; ++i)
    {
        for (int j = 0; j < num_dimensions; ++j)
        {
            dataset(j, i) = normal_dist(rng); // 使用随机数生成器生成随机数据
        }
    }





    // 计算均值
    Eigen::Vector2d mean = dataset.rowwise().mean();

    // 计算协方差
    Eigen::MatrixXd centered = dataset.colwise() - mean;
    Eigen::MatrixXd covariance = (centered * centered.transpose()) / static_cast<double>(dataset.cols() - 1); //分母是N-1

    // 输出结果
    std::cout << "Mean:\n" << mean << std::endl;
    std::cout << "Covariance:\n" << covariance << std::endl;
    int count = 0;
    // 剔除标准差之外的噪声点
    double sigma_threshold = 2.0; // 根据需求设置阈值,3 就是3sigma开外了
    for (int i = 0; i < dataset.cols(); ++i)// 每一个样本
    {
        Eigen::Vector2d point = dataset.col(i); //里面包含了 x,y的信息(如果是二维的话)
        Eigen::Vector2d diff = point - mean;
        double mahalanobis_distance = diff.transpose() * covariance.inverse() * diff;

        if (mahalanobis_distance > sigma_threshold*sigma_threshold)
        {
            count++;
            // 噪声点，剔除操作
            // 这里可以根据需要执行相关的操作，比如删除该点或标记为噪声等
        }
    }
        std::cout << "remaining percentage is : " << 100.0 - (double)count/10000.0*100.0 << std::endl;

    int num1, num2;

    std::cout << "请输入第一个整数：";
    std::cin >> num1;

    std::cout << "请输入第二个整数：";
    std::cin >> num2;

    if (num1 == num2) {
        std::cout << "两个整数相等！" << std::endl;
    } else {
        std::cout << "两个整数不相等！" << std::endl;
    }





    return 0;







}

#endif