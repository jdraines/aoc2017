cmake_minimum_required(VERSION 3.10)

project(aoc_day2)

include_directories(../input)

add_executable(day02-2 day02-2.cpp ../input/aoc_input.cpp)
set_property(TARGET day02-2 PROPERTY CXX_STANDARD 17)
