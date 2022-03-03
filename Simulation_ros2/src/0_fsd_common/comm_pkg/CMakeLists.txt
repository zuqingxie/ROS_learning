cmake_minimum_required(VERSION 3.5)
project(comm_pkg)

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

#Find catkin and any catkin packages
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)


## Generate messages in the 'msg' folder
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Cone.msg"
  "msg/ConeArray.msg"
  "msg/FSGLogger.msg"
  "msg/MasterLogic.msg"
  "msg/SdcOut.msg"
  "msg/TrackInfo.msg"
  "msg/VehiclePose.msg"
  "msg/VehicleState.msg"
  "msg/VehicleStateDT.msg"
  "msg/VehicleSystem.msg"
  "msg/BoundingBox.msg"
  "msg/BoundingBoxes.msg"
  "msg/PoseVel.msg"
  "msg/RawMap.msg"
  "msg/Logging.msg"
  "msg/LogMsgControl.msg"
  "msg/WholeTrack.msg"
  "msg/TrajectoryPoint.msg"
  "msg/HealthMsg.msg"
  DEPENDENCIES builtin_interfaces std_msgs geometry_msgs
)

ament_export_dependencies(rosidl_default_runtime builtin_interfaces std_msgs geometry_msgs)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  ${Boost_INCLUDE_DIRS}
)

install(
  FILES bridge_mapping_rules.yaml
  DESTINATION share/${PROJECT_NAME}
)

#add_executable(vehicle_comm_pub src/vehicle_comm_pub.cpp)
#target_link_libraries(vehicle_comm_pub ${catkin_LIBRARIES})
#add_dependencies(vehicle_comm_pub vehicle_communication_pkg_generate_messages_cpp)

#add_executable(vehicle_comm_sub src/vehicle_comm_sub.cpp)
#target_link_libraries(vehicle_comm_sub ${catkin_LIBRARIES})
#add_dependencies(vehicle_comm_sub vehicle_communication_pkg_generate_messages_cpp)
ament_package()
