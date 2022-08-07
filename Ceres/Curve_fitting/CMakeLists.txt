cmake_minimum_required(VERSION 2.8)
project(curve_fitting)
set( CMAKE_CXX_FLAGS "-std=c++17" )

MESSAGE(STATUS "曲线拟合") #打印相关消息消息

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

add_executable(runable_name curve_fitting.cpp)
target_link_libraries(runable_name ${CERES_LIBRARIES}) #这个可执行文件所需要的库