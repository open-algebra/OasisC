cmake_minimum_required(VERSION 3.28)
project(OasisC C)

include(FetchContent)
include(cmake/FetchMUnit.cmake)

add_executable(OasisCTests main.c)
target_link_libraries(OasisCTests PUBLIC OasisC munit)