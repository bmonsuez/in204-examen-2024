cmake_minimum_required(VERSION 3.0.0)

project(part1 VERSION 0.1.0)

add_executable(part1 interval.cpp)

set_property(TARGET part1 PROPERTY CXX_STANDARD_REQUIRED TRUE)
set_property(TARGET part1 PROPERTY CXX_STANDARD 20)