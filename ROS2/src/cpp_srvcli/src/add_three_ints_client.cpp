#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/add_three_ints.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

class Service : public rclcpp::Node{
  public:
      Service(int argc, char **argv): Node("add_three_ints_client")
    {
    client = this->create_client<tutorial_interfaces::srv::AddThreeInts>("add_three_ints");
    request_function();
    // request->a = atoll(argv[1]); //将参数取出来
    // request->c = atoll(argv[3]);
    // request->b = atoll(argv[2]);
    // auto  timer_ = this->create_wall_timer(3s, std::bind(&Service::request_function, this));
    }
  private:
    rclcpp::Client<tutorial_interfaces::srv::AddThreeInts>::SharedPtr client;
    void request_function(){
      while (!this->client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
          RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "在等到服务节点的时候系统中断Ctrl+c！");
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "服务节点还不可用，请再等等。。。");
      }
      auto request = std::make_shared<tutorial_interfaces::srv::AddThreeInts::Request>();
      request->a = 1; //将参数取出来
      request->b = 2;
      request->c = 3;
      auto result = this->client->async_send_request(request);
      // auto status = result.wait_for(10s);  //not spinning here!
      // if (status == std::future_status::ready){
      // rclcpp::node_interfaces::NodeBaseInterface::SharedPtr a = rspin_until_future_complete(this, result);
      // rclcpp::node_interfaces::NodeBaseInterface::

      if(rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == rclcpp::FutureReturnCode::SUCCESS){
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "和Sum是: %ld", result.get()->sum);
      }
      else
      {
          RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "寻求服务的时候时间太长了，失败了！！！");
      }
    };  

};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  /*
    这个是没有写进class的代码！！也能用，具体看官网教程！！！
  */ 
  // if (argc != 4) {// 判断输入的参数是多少个。。
  //     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "要使用下面这个格式: add_three_ints_client X Y Z");
  //     return 1; //? 一会儿试一下
  // }

  // std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_three_ints_client");
  // rclcpp::Client<tutorial_interfaces::srv::AddThreeInts>::SharedPtr client =
  //   node->create_client<tutorial_interfaces::srv::AddThreeInts>("add_three_ints");

  // auto request = std::make_shared<tutorial_interfaces::srv::AddThreeInts::Request>();
  // request->a = atoll(argv[1]); //将参数取出来
  // request->b = atoll(argv[2]);
  // request->c = atoll(argv[3]);


  // while (!client->wait_for_service(1s)) {
  //   if (!rclcpp::ok()) {
  //     RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "在等到服务节点的时候系统中断Ctrl+c！");
  //     return 0;
  //   }
  //   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "服务节点还不可用，请再等等。。。");
  // }
  // // request after the client is available
  // auto result = client->async_send_request(request);
  // // spin and Wait until the result get back. While loop is not needed
  // if (rclcpp::spin_until_future_complete(node, result) ==
  //   rclcpp::FutureReturnCode::SUCCESS)
  // {
  //   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "和Sum是: %ld", result.get()->sum);
  // } else {
  //   RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "寻求服务的时候失败了！！！");
  // }
  auto node = std::make_shared<Service>(argc,argv);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
