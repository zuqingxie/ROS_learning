#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

// 定义数据点结构体
struct Point {
    double x, y;
    int cluster; // 存储所属簇的索引
};

// 计算两点之间的欧氏距离
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// 执行K-Means算法
void kMeans(std::vector<Point>& points, std::vector<Point>& centroids, int k, int maxIterations) {
    int numPoints = points.size();
    int numCentroids = centroids.size();

    for (int iter = 0; iter < maxIterations; ++iter) {
        // 分配每个数据点到最近的聚类中心
        for (int i = 0; i < numPoints; ++i) {
            double minDist = distance(points[i], centroids[0]);
            int minIndex = 0;

            for (int j = 1; j < numCentroids; ++j) {
                double dist = distance(points[i], centroids[j]);
                if (dist < minDist) {
                    minDist = dist;
                    minIndex = j;
                }
            }

            points[i].cluster = minIndex;
        }

        // 计算新的聚类中心
        for (int i = 0; i < numCentroids; ++i) {
            double sumX = 0.0, sumY = 0.0;
            int count = 0;

            for (int j = 0; j < numPoints; ++j) {
                if (points[j].cluster == i) {
                    sumX += points[j].x;
                    sumY += points[j].y;
                    ++count;
                }
            }

            if (count > 0) {
                centroids[i].x = sumX / count;
                centroids[i].y = sumY / count;
            }
        }
    }
}

int main() {
    // 创建二维数据点和初始聚类中心
    std::vector<Point> points = { {1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}, {10.0, 11.0}, {11.0, 12.0}, {12.0, 13.0} };
    std::vector<Point> centroids = { {1.0, 2.0}, {10.0, 11.0} };

    int k = centroids.size(); // 聚类数
    int maxIterations = 100; // 最大迭代次数

    // 执行K-Means算法
    kMeans(points, centroids, k, maxIterations);

    // 打印每个数据点所属的聚类
    for (const Point& p : points) {
        std::cout << "Point (" << p.x << ", " << p.y << ") belongs to Cluster " << p.cluster << std::endl;
    }

    return 0;
}