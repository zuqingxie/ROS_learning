#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <rosbag2_cpp/writer.hpp>

using std::placeholders::_1;
/*
这个package教我们如何在程序里面直接记录rosbag
具体的方法是,创建一个接收器,callback里面写入接受到的信息
不一样的是用到了:rclcpp::SerializedMessage..bag本来就需要序列化
这个教程的后面还加入了如何将自己创建的 数据写进rosbag里面
*/
class SimpleBagRecorder : public rclcpp::Node
{
public:
  SimpleBagRecorder()
  : Node("simple_bag_recorder")
  {
    writer_ = std::make_unique<rosbag2_cpp::Writer>();

    writer_->open("my_bag");

    subscription_ = create_subscription<std_msgs::msg::String>(
      "chatter", 10, std::bind(&SimpleBagRecorder::topic_callback, this, _1));
  }

private:
  void topic_callback(std::shared_ptr<rclcpp::SerializedMessage> msg) const
  {
    rclcpp::Time time_stamp = this->now();

    writer_->write(*msg, "chatter", "std_msgs/msg/String", time_stamp);
  }

  rclcpp::Subscription<rclcpp::SerializedMessage>::SharedPtr subscription_;
  std::unique_ptr<rosbag2_cpp::Writer> writer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleBagRecorder>());
  rclcpp::shutdown();
  return 0;
}