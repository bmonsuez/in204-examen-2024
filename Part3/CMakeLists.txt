cmake_minimum_required(VERSION 3.0.0)

project(part3 VERSION 0.1.0)

add_executable(part3 interval.cpp)

set_property(TARGET part3 PROPERTY CXX_STANDARD_REQUIRED TRUE)
set_property(TARGET part3 PROPERTY CXX_STANDARD 20)