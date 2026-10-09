cmake_minimum_required(VERSION 4.3)
project(bullsAndCows)

set(CMAKE_CXX_STANDARD 20)

add_executable(bullsAndCows main.cpp
        digitOperations.h
        digitOperations.cpp
        consoleMessages.h
        consoleMessages.cpp)
