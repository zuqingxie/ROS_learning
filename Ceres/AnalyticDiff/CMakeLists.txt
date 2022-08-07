cmake_minimum_required(VERSION 2.8)
project(AnalyticDiff)
set( CMAKE_CXX_FLAGS "-std=c++17" )

MESSAGE(STATUS "Ceres solver using Analytic Differentiation") #打印相关消息消息

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

add_executable(runable_name AnalyticDiff.cpp)
target_link_libraries(runable_name ${CERES_LIBRARIES}) #这个可执行文件所需要的库
