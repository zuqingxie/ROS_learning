cmake_minimum_required(VERSION 2.8)
project(inference)
set( CMAKE_CXX_FLAGS "-std=c++17" )

MESSAGE(STATUS "曲线拟合") #打印相关消息消息

find_package(CUDA REQUIRED)
include_directories(${CUDA_INCLUDE_DIRS})


add_executable(runable_name test.cpp)

target_link_libraries(runable_name ${NVINFER_LIBRARY})
target_link_libraries(runable_name ${CUDA_LIBRARIES}) #这个可执行文件所需要的库