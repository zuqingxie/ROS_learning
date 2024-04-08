#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
    bool visited;
    int cluster_id;

    Point(double _x, double _y) : x(_x), y(_y), visited(false), cluster_id(-1) {}
};

// Calculate Euclidean distance between two points
double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Find all neighbor points within epsilon distance
std::vector<Point*> getNeighbors(const std::vector<Point>& points, const Point& center, double epsilon) {
    std::vector<Point*> neighbors;
    for (auto& p : points) {
        if (calculateDistance(p, center) <= epsilon) {
            neighbors.push_back(const_cast<Point*>(&p));
        }
    }
    return neighbors;
}

// Expand a cluster from a seed point
void expandCluster(std::vector<Point>& points, Point& point, int cluster_id, double epsilon, int min_pts) {
    std::vector<Point*> neighbors = getNeighbors(points, point, epsilon);

    if (neighbors.size() < min_pts) {
        point.cluster_id = -1;  // Mark point as noise
    } else {
        point.cluster_id = cluster_id;
        for (auto& neighbor : neighbors) {
            if (!neighbor->visited) {
                neighbor->visited = true;
                expandCluster(points, *neighbor, cluster_id, epsilon, min_pts);
            }
            if (neighbor->cluster_id == -1) {
                neighbor->cluster_id = cluster_id;
            }
        }
    }
}

// DBSCAN clustering algorithm
void DBSCAN(std::vector<Point>& points, double epsilon, int min_pts) {
    int cluster_id = 0;

    for (auto& point : points) {
        if (!point.visited) {
            point.visited = true;
            std::vector<Point*> neighbors = getNeighbors(points, point, epsilon);

            if (neighbors.size() < min_pts) {
                point.cluster_id = -1;  // Mark point as noise
            } else {
                point.cluster_id = cluster_id;
                expandCluster(points, point, cluster_id, epsilon, min_pts);
                cluster_id++;
            }
        }
    }
}

int main() {
    // Sample data
    std::vector<Point> points = {
        {1.0, 2.0},
        {1.0, 2.0},
        {1.0, 2.0},
        {2.0, 3.0},
        {3.0, 2.0},
        {6.0, 5.0},
        {7.0, 5.0},
        {8.0, 6.0},
    };

    double epsilon = 1.0;
    int min_pts = 2;

    // Perform DBSCAN clustering
    DBSCAN(points, epsilon, min_pts);

    // Print the results
    for (const auto& point : points) {
        if (point.cluster_id == -1) {
            std::cout << "Point (" << point.x << ", " << point.y << ") is noise." << std::endl;
        } else {
            std::cout << "Point (" << point.x << ", " << point.y << ") belongs to cluster " << point.cluster_id << std::endl;
        }
    }

    return 0;
}