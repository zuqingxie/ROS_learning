#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"     // CHANGE 使用自定义的消息类型
#include "comm_pkg/msg/vehicle_state_dt.hpp"
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    subscription_ = this->create_subscription<comm_pkg::msg::VehicleStateDT>(         
      "/vehicle_state", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    publisher_ = this->create_publisher<comm_pkg::msg::VehicleStateDT>("/vehicle_state_test",1);
    
  }

private:
  void topic_callback(const comm_pkg::msg::VehicleStateDT::SharedPtr msg) const       
  {
    // this->publisher_->publish(*msg);   
    // RCLCPP_INFO(this->get_logger(),"x velocity is: %.2f ", msg->vx);   
    // RCLCPP_INFO(this->get_logger(),"y velocity is: %.2f ", msg->vy);   
    // RCLCPP_INFO(this->get_logger(),"theta velocity is: %.2f ", msg->vtheta);   
    RCLCPP_INFO(this->get_logger(),"x accel is: %.2f ", msg->ax);   
    RCLCPP_INFO(this->get_logger(),"y accel is: %.2f ", msg->ay);   
    RCLCPP_INFO(this->get_logger(),"theta accel is: %.2f ", msg->atheta);   
  }
  rclcpp::Subscription<comm_pkg::msg::VehicleStateDT>::SharedPtr subscription_;      
  rclcpp::Publisher<comm_pkg::msg::VehicleStateDT>::SharedPtr publisher_;       
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // rclcpp::Rate loop_rate(1);
  // while (true){

    rclcpp::spin(std::make_shared<MinimalSubscriber>());
  //   loop_rate.sleep();
  // }
  
  rclcpp::shutdown();
  return 0;
}