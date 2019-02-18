#参考：https://blog.csdn.net/DumpDoctorWang/article/details/82691186

cmake_minimum_required(VERSION 3.12)
project(1)

set(CMAKE_CXX_STANDARD 11)



set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda-8.0)

find_package(CUDA REQUIRED)

# 设置公共源文件
file(GLOB COMMON common.h common.cpp)

# 添加*.cu源文件
file(GLOB CU *.cu)


# 添加包含目录
include_directories(${CUDA_INCLUDE_DIRS})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)



CUDA_ADD_EXECUTABLE(kernel # target名
        ${CU}  # 添加*.cu源文件
        ${COMMON}  # 添加
        main.cpp
        )
target_link_libraries(kernel ${CUDA_CUDA_LIBRARY})