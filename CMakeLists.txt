cmake_minimum_required(VERSION 3.10)

project(Advent_of_Code_2024)

add_executable(day_1_part_1 Day_1/day_1_part_1.cpp InputFiles/InputFiles.cpp Divide_and_Conquer/Divide_and_Conquer.cpp)
add_executable(day_1_part_2 Day_1/day_1_part_2.cpp InputFiles/InputFiles.cpp Divide_and_Conquer/Divide_and_Conquer.cpp)

include_directories(${CMAKE_SOURCE_DIR})