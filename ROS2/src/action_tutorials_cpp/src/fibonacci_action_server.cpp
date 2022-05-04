#include <functional>
#include <memory>
#include <thread>

#include "action_tutorials_interfaces/action/fibonacci.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "action_tutorials_cpp/visibility_control.h"

namespace action_tutorials_cpp
{
class FibonacciActionServer : public rclcpp::Node
{
public:
  using Fibonacci = action_tutorials_interfaces::action::Fibonacci;
  using GoalHandleFibonacci = rclcpp_action::ServerGoalHandle<Fibonacci>;

  ACTION_TUTORIALS_CPP_PUBLIC
  explicit FibonacciActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("fibonacci_action_server", options)
  {
    using namespace std::placeholders;

    this->action_server_ = rclcpp_action::create_server<Fibonacci>(
      this,
      "fibonacci",
      std::bind(&FibonacciActionServer::handle_goal, this, _1, _2), //可以都看作是回调函数
      std::bind(&FibonacciActionServer::handle_cancel, this, _1),
      std::bind(&FibonacciActionServer::handle_accepted, this, _1));
      RCLCPP_INFO(this->get_logger(), "server构造函数");

  }

private:
  rclcpp_action::Server<Fibonacci>::SharedPtr action_server_;
    
    // ID 用来处理一个新的action目标，无论如何都接受，返回response
  rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const Fibonacci::Goal> goal) //这个类型是在编译 Fibonacci的action时自动生成的
  {
    RCLCPP_INFO(this->get_logger(), "1.接受到了 %d 非伯纳切级数的目标", goal->order);
    (void)uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }
    // 处理但接收到取消的时候如何处理，告诉别人接受取消
  rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "收到取消的请求");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }
    // 开辟一个全新的线程去执行它
  void handle_accepted(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
  {
    using namespace std::placeholders;
    RCLCPP_INFO(this->get_logger(), "开始开辟一个线程来执行代码");
    // this needs to return quickly to avoid blocking the executor, so spin up a new thread
    std::thread{std::bind(&FibonacciActionServer::execute, this, _1), goal_handle}.detach();
    RCLCPP_INFO(this->get_logger(), "完成开辟一个线程，代码继续运行");
  }


            /*
            # Request
            int32 order
            ---
            # Result
            int32[] sequence 是一个向量！
            ---
            # Feedback
            int32[] partial_sequence  
            */
    // 真正被执行的处理的逻辑顺序
  void execute(const std::shared_ptr<GoalHandleFibonacci> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "执行主要的程序");
    rclcpp::Rate loop_rate(1);
    const auto goal = goal_handle->get_goal(); //
    auto feedback = std::make_shared<Fibonacci::Feedback>();
    auto & sequence = feedback->partial_sequence; // feedback->partial_sequence 取了一个别名叫做 sequence
    sequence.push_back(0);
    sequence.push_back(1);
    auto result = std::make_shared<Fibonacci::Result>();// 

    for (int i = 1; (i < goal->order) && rclcpp::ok(); ++i) { // goal->order 获取goal值
      // Check if there is a cancel request
      if (goal_handle->is_canceling()) {
        result->sequence = sequence;  // result->sequence 赋值result
        goal_handle->canceled(result);  // result.code = rclcpp_action::ResultCode::CANCELED
        RCLCPP_INFO(this->get_logger(), "中途行动被取消了");
        return;
      }
      // Update sequence
      sequence.push_back(sequence[i] + sequence[i - 1]);
      // Publish feedback
      goal_handle->publish_feedback(feedback);
      RCLCPP_INFO(this->get_logger(), "返回给client feedback，在client那边调用feedback_callback()");

      loop_rate.sleep();
    }

    // Check if goal is done
    if (rclcpp::ok()) {
      result->sequence = sequence;
      goal_handle->succeed(result); // result.code = rclcpp_action::ResultCode::SUCCEEDED
      RCLCPP_INFO(this->get_logger(), "返回给client result，在client那边会调用result_callbacl()");
    }

    RCLCPP_INFO(this->get_logger(), "执行完毕");
  }
};  // class FibonacciActionServer

}  // namespace action_tutorials_cpp

RCLCPP_COMPONENTS_REGISTER_NODE(action_tutorials_cpp::FibonacciActionServer)