#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/add_three_ints.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc != 4) {// 判断输入的参数是多少个。。
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "要使用下面这个格式: add_three_ints_client X Y Z");
      return 1; //? 一会儿试一下
  }

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_three_ints_client");
  rclcpp::Client<tutorial_interfaces::srv::AddThreeInts>::SharedPtr client =
    node->create_client<tutorial_interfaces::srv::AddThreeInts>("add_three_ints");

  auto request = std::make_shared<tutorial_interfaces::srv::AddThreeInts::Request>();
  request->a = atoll(argv[1]); //将参数取出来
  request->b = atoll(argv[2]);
  request->c = atoll(argv[3]);

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "在等到服务节点的时候系统中断Ctrl+c！");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "服务节点还不可用，请再等等。。。");
  }

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "和Sum是: %ld", result.get()->sum);
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "寻求服务的时候失败了！！！");
  }

  rclcpp::shutdown();
  return 0;
}