cmake_minimum_required(VERSION 2.8)
project(ceres)
set( CMAKE_CXX_FLAGS "-std=c++17" )

MESSAGE(STATUS "Project: HALLO WORLD") #打印相关消息消息

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

add_executable(runable_name use_ceres.cpp)
target_link_libraries(runable_name ${CERES_LIBRARIES}) #这个可执行文件所需要的库


# https://segmentfault.com/a/1190000018491801