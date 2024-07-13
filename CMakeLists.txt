cmake_minimum_required(VERSION 3.4)
project(calculation)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(GLOB SRC_SRC "sources/calculation.cpp")

add_executable(calculation sources/calculation.cpp)
