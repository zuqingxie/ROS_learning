cmake_minimum_required(VERSION 3.5)
project(more_interfaces)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 创建一个变量
set(msg_files
  "msg/AddressBook.msg"
)
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rclcpp REQUIRED)



rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)

# 这个是为啥呢,反正加上肯定么没错
ament_export_dependencies(rosidl_default_runtime)



# 节点往下面放
add_executable(publish_address_book
  src/publish_address_book.cpp
)
# 这个节点依赖的外部包只有rclcpp
ament_target_dependencies(publish_address_book
  "rclcpp"
)

install(TARGETS publish_address_book
 DESTINATION lib/${PROJECT_NAME})

 # 由于还使用到了自身的包,所以要加上这一句,将自身的包给到自身的节点
rosidl_target_interfaces(publish_address_book
 ${PROJECT_NAME} "rosidl_typesupport_cpp")



ament_package()
