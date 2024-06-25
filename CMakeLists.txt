cmake_minimum_required(VERSION 3.28)
project(OasisC CXX C)

add_library(OasisC src/Expression.cpp)
target_include_directories(OasisC PUBLIC include)

add_subdirectory(tests)