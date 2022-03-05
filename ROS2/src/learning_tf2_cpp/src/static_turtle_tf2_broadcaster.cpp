
/*
发布 static_transform_publsiher 有三种方法：
  一。 自定义
    可以自由实现功能，如四元数转换之类的
    ros2 run learning_tf2_cpp static_turtle_tf2_broadcaster mystaticturtle 0 0 1 0 0 0 （定义了parent frame 是world）
  二。使用自带的tf2_ros包
    旋转表示：
      ros2 run tf2_ros static_transform_publisher x y z yaw pitch roll frame_id child_frame_id
    四元数表达：
      ros2 run tf2_ros static_transform_publisher x y z qx qy qz qw frame_id child_frame_id
  三。ros2 launch
    ```
      from launch import LaunchDescription
      from launch_ros.actions import Node

      def generate_launch_description():
        return LaunchDescription([
            Node(
                  package='tf2_ros',
                  executable='static_transform_publisher',
                  arguments = ['0', '0', '1', '0', '0', '0', 'world', 'mystaticturtle']
            ),
        ])
    ```
*/






// 保函要发布的数据类型
#include <geometry_msgs/msg/transform_stamped.hpp>

//用到rclcpp里面的节点类
#include <rclcpp/rclcpp.hpp>

// 欧拉角和四元数之间的转换
#include <tf2/LinearMath/Quaternion.h>

#include <tf2_ros/static_transform_broadcaster.h>

#include <memory>

using std::placeholders::_1;

class StaticFramePublisher : public rclcpp::Node
{
public:
  explicit StaticFramePublisher(char * transformation[])
  : Node("static_turtle_tf2_broadcaster")
  {
    tf_publisher_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);

    // Publish static transforms once at startup
    this->make_transforms(transformation);
  }

private:
  void make_transforms(char * transformation[])
  {
    rclcpp::Time now = this->get_clock()->now();
    geometry_msgs::msg::TransformStamped t;

    t.header.stamp = now;
    t.header.frame_id = "world";
    t.child_frame_id = transformation[1];

    t.transform.translation.x = atof(transformation[2]);
    t.transform.translation.y = atof(transformation[3]);
    t.transform.translation.z = atof(transformation[4]);
    tf2::Quaternion q;
    q.setRPY(
      atof(transformation[5]),
      atof(transformation[6]),
      atof(transformation[7]));
    t.transform.rotation.x = q.x();
    t.transform.rotation.y = q.y();
    t.transform.rotation.z = q.z();
    t.transform.rotation.w = q.w();

    tf_publisher_->sendTransform(t);
  }
  std::shared_ptr<tf2_ros::StaticTransformBroadcaster> tf_publisher_;
};

int main(int argc, char * argv[])
{
  auto logger = rclcpp::get_logger("logger");

  // Obtain parameters from command line arguments
  if (argc != 8) {
    RCLCPP_INFO(
      logger, "Invalid number of parameters\nusage: "
      "ros2 run learning_tf2_cpp static_turtle_tf2_broadcaster "
      "child_frame_name x y z roll pitch yaw");
    return 1;
  }

  // As the parent frame of the transform is `world`, it is
  // necessary to check that the frame name passed is different
  if (strcmp(argv[1], "world") == 0) {
    RCLCPP_INFO(logger, "Your static turtle name cannot be 'world'");
    return 1;
  }

  // Pass parameters and initialize node
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<StaticFramePublisher>(argv));
  rclcpp::shutdown();
  return 0;
}
