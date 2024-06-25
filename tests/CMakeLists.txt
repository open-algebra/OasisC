cmake_minimum_required(VERSION 3.28)
project(OasisC C)

add_executable(OasisCTests main.c)
target_link_libraries(OasisCTests PUBLIC OasisC)