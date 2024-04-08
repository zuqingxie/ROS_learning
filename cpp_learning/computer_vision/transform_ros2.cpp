#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2/transform_datatypes.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

class LaserScanTransformer : public rclcpp::Node {
public:
    LaserScanTransformer() : Node("laser_scan_transformer") {
        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
        
        laser_scan_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "laser_scan", 10, std::bind(&LaserScanTransformer::laserScanCallback, this, std::placeholders::_1));
        
        lidar_pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
            "lidar_pose", 10, std::bind(&LaserScanTransformer::lidarPoseCallback, this, std::placeholders::_1));
        
        transformed_scan_pub_ = this->create_publisher<sensor_msgs::msg::LaserScan>("transformed_scan", 10);
    }

private:
    void laserScanCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
        // Check if we have the lidar pose available
        if (!lidar_pose_) {
            RCLCPP_WARN(this->get_logger(), "No lidar pose available. Cannot transform laser scan.");
            return;
        }

        // Transform the laser scan data based on the lidar pose
        sensor_msgs::msg::LaserScan transformed_scan = *msg;
        tf2::doTransform(*msg, transformed_scan, lidar_pose_.value());

        transformed_scan_pub_->publish(transformed_scan);
    }

    void lidarPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
        // Store the lidar pose for later use
        lidar_pose_ = msg->header;
    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_scan_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr lidar_pose_sub_;
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr transformed_scan_pub_;
    std::optional<geometry_msgs::msg::TransformStamped> lidar_pose_;
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<LaserScanTransformer>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
