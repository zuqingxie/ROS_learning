#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/subscription_options.hpp"

#include "std_msgs/msg/string.hpp"
#include "tutorial_interfaces/msg/num.hpp"


/*
这个教程教我们如何使节点额外发布/statistics话题,来观测接受节点的频率和统计分布.可以用来很好得查看整个通信的质量
主要用作检测和调试使用
*/
class MinimalSubscriberWithTopicStatistics : public rclcpp::Node
{
public:
  MinimalSubscriberWithTopicStatistics()
  : Node("minimal_subscriber_with_topic_statistics")
  {
    // manually enable topic statistics via options
    auto options = rclcpp::SubscriptionOptions();
    options.topic_stats_options.state = rclcpp::TopicStatisticsState::Enable;

    // configure the collection window and publish period (default 1s)
    options.topic_stats_options.publish_period = std::chrono::seconds(10);

    // configure the topic name (default '/statistics')
    // options.topic_stats_options.publish_topic = "/topic_statistics"

    // auto callback = [this](std_msgs::msg::String::SharedPtr msg) {
    //     this->topic_callback(msg);
    //   };
      auto callback = [this](tutorial_interfaces::msg::Num::SharedPtr msg) {
      this->topic_callback(msg);
    };

    subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>(
      "topic", 10, callback, options);
  }

private:
  void topic_callback(const tutorial_interfaces::msg::Num::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(),  "I heard: '%d'", msg->num);
  }
  rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriberWithTopicStatistics>());
  rclcpp::shutdown();
  return 0;
}