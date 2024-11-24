cmake_minimum_required(VERSION 3.0.0)

project(part5 VERSION 0.1.0)

add_executable(part5 interval.cpp)

set_property(TARGET part5 PROPERTY CXX_STANDARD_REQUIRED TRUE)
set_property(TARGET part5 PROPERTY CXX_STANDARD 20)
