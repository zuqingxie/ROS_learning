import rclpy
import rclpy.node

class MinimalParam(rclpy.node.Node):
    def __init__(self):
        super().__init__('minimal_param_node')
        timer_period = 2  # seconds
        # 每两秒钟开始一次callback
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        ###########
        #optional##
        ###########
        from rcl_interfaces.msg import ParameterDescriptor
        my_parameter_descriptor = ParameterDescriptor(description='This parameter is mine!')

        

        # 定义自己的变量
        self.declare_parameter('my_parameter', 'world', my_parameter_descriptor)

    def timer_callback(self):
        # 获得目前已有的parameter
        my_param = self.get_parameter('my_parameter').get_parameter_value().string_value
        
        self.get_logger().info('Hello %s!' % my_param)

        my_new_param = rclpy.parameter.Parameter(
            'my_parameter',
            rclpy.Parameter.Type.STRING,
            'world'
        )
        # 设置一个新的parameter 列表
        all_new_parameters = [my_new_param]
        self.set_parameters(all_new_parameters)

def main():
    rclpy.init()
    node = MinimalParam()
    rclpy.spin(node)

if __name__ == '__main__':
    main()