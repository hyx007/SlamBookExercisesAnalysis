cmake_minimum_required( VERSION 2.8 )
project( geometry )

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )

add_executable( question5 question5.cpp)
add_executable( question6 question6.cpp)
add_executable( question7 question7.cpp)

