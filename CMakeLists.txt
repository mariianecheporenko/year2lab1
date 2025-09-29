cmake_minimum_required(VERSION 3.29)
project(year2lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Werror")

add_executable(year2lab1
        main.cpp
        Statistics.h
        RandomCell.h
        Statistics.cpp
        Board.cpp
        experiment.h
        RandomCell.cpp
        experiment.cpp)
