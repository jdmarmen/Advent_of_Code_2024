cmake_minimum_required(VERSION 3.10)

project(Advent_of_Code_2024)

add_executable(day_1_part_1
    Day_1/day_1_part_1.cpp
    InputFiles/InputFiles.cpp
    Divide_and_Conquer/Divide_and_Conquer.cpp
)
add_executable(day_1_part_2
    Day_1/day_1_part_2.cpp
    InputFiles/InputFiles.cpp
    Divide_and_Conquer/Divide_and_Conquer.cpp
)
add_executable(day_11_part_1-2
    Day_11/day_11_part_1-2.cpp
    InputFiles/InputFiles.cpp
    Dynamic_Programming/Dynamic_Programming.cpp
    Binary_Tree/BSTree.h
    Binary_Tree/BSTreeDict.h
    Binary_Tree/TableEntry.h
)
add_executable(day_19_part_1
    Day_19/day_19_part_1.cpp
    InputFiles/InputFiles.cpp
    Hash_Table/hash_table.cpp
)
add_executable(day_5_part_1
    Day_5/day_5_part_1.cpp
    InputFiles/InputFiles.cpp
    Graph/graph.cpp
)

include_directories(${CMAKE_SOURCE_DIR})