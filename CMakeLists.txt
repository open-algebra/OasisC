cmake_minimum_required(VERSION 3.28)
project(OasisC CXX C)

add_subdirectory(libs/Oasis)

add_library(OasisC
        src/Expression.cpp
        src/Real.cpp
        src/Add.cpp
        src/Subtract.cpp)

target_include_directories(OasisC PUBLIC include)
target_link_libraries(OasisC PUBLIC Oasis::Oasis)

add_subdirectory(tests)