cmake_minimum_required(VERSION 3.10)

project(aoc_day3)

include_directories(
    ../spiral_memory 
    ~/cpp/lib/boost
    )

add_executable(
    day03-2.out # executable name
    ../spiral_memory/spiral_memory.cpp 
    day03-2.cpp
    )

set_property(
    TARGET day03-2.out
    PROPERTY CXX_STANDARD 17
    )
