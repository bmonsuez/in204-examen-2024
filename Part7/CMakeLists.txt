cmake_minimum_required(VERSION 3.0.0)

project(part7 VERSION 0.1.0)

add_executable(part7 interval.cpp)

set_property(TARGET part7 PROPERTY CXX_STANDARD_REQUIRED TRUE)
set_property(TARGET part7 PROPERTY CXX_STANDARD 20)
