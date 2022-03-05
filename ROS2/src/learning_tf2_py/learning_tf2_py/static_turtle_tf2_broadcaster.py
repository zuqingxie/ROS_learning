# Copyright 2021 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import sys

# 这个是数据格式给到tf tree
from geometry_msgs.msg import TransformStamped

import rclpy
from rclpy.node import Node

from tf2_ros.static_transform_broadcaster import StaticTransformBroadcaster

# 提供欧拉角和四元数之间的转换
import tf_transformations


class StaticFramePublisher(Node):
    """
    Broadcast transforms that never change. 发布不会变化的左边关系所以是Static的

    This example publishes transforms from `world` to a static turtle frame.
    The transforms are only published once at startup, and are constant for all
    time.
    """

    def __init__(self, transformation):
        super().__init__('static_turtle_tf2_broadcaster')

        # 实例化一个 StaticTransformBroadcaster
        self._tf_publisher = StaticTransformBroadcaster(self)

        # Publish static transforms once at startup 这是一种静态的发布，在echo的时候只会出现一次，不会一直刷新的那种
        self.make_transforms(transformation)

    def make_transforms(self, transformation):
        static_transformStamped = TransformStamped()
        static_transformStamped.header.stamp = self.get_clock().now().to_msg() # 如何写入时间戳
        static_transformStamped.header.frame_id = 'world' # parent frame id
        static_transformStamped.child_frame_id = sys.argv[1] # child frame id
        # 填充六个位姿
        static_transformStamped.transform.translation.x = float(sys.argv[2])
        static_transformStamped.transform.translation.y = float(sys.argv[3])
        static_transformStamped.transform.translation.z = float(sys.argv[4])
        # 将欧拉表示成四元数
        quat = tf_transformations.quaternion_from_euler(
            float(sys.argv[5]), float(sys.argv[6]), float(sys.argv[7]))
        static_transformStamped.transform.rotation.x = quat[0]
        static_transformStamped.transform.rotation.y = quat[1]
        static_transformStamped.transform.rotation.z = quat[2]
        static_transformStamped.transform.rotation.w = quat[3]

        # 这个类里面有发布的对应方程
        self._tf_publisher.sendTransform(static_transformStamped)


def main():
    logger = rclpy.logging.get_logger('logger')

    # 从命令行获得参数
    if len(sys.argv) < 8:
        logger.info('Invalid number of parameters. Usage: \n'
                    '$ ros2 run turtle_tf2_py static_turtle_tf2_broadcaster'
                    'child_frame_name x y z roll pitch yaw')
        sys.exit(0)
    else:
        if sys.argv[1] == 'world':
            logger.info('Your static turtle name cannot be "world"')
            sys.exit(0)

    # pass parameters and initialize node
    rclpy.init()
    node = StaticFramePublisher(sys.argv)
    
    # 尝试spin 除非被叫停了
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    rclpy.shutdown()
