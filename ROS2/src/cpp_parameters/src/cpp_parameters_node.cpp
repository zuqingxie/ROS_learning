#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <string>
#include <functional>

using namespace std::chrono_literals;


// 定义了一个类，继承至 rclcpp：：Node
class ParametersClass: public rclcpp::Node
{
  public:
  //构造函数
    ParametersClass()
      : Node("parameter_node") //节点名称
    {
    //这一部分是构造函数里面的，在实例化的时候就会运行 
    //declare_parameter<Template>(string类型的参数名称,Template 默认数据-因为如果外面有数据进来的话会被覆盖的)
      this->declare_parameter<std::string>("my_parameter", "world");
      //初始化一个实例：timer_。用来实现，每一秒钟callback一次。create_wall_timer(时隔多久，callbackfunction，callbackgroup)
      timer_ = this->create_wall_timer(
      1000ms, std::bind(&ParametersClass::respond, this));
    }
    void respond()
    {
        //get_parameter()
      this->get_parameter("my_parameter", parameter_string_);
      //Node有get_logger(),来输出日志
      RCLCPP_INFO(this->get_logger(), "Hello %s", parameter_string_.c_str());
    }
  private:
    std::string parameter_string_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ParametersClass>());
  rclcpp::shutdown();
  return 0;
}