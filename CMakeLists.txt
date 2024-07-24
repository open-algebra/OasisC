cmake_minimum_required(VERSION 3.22)
project(OasisC CXX C)

add_subdirectory(libs/Oasis)

set(OasisC_SOURCES
        src/Expression.cpp
        src/Real.cpp
        src/Add.cpp
        src/Subtract.cpp
        src/Multiply.cpp
        src/Divide.cpp)

if (DEFINED EMSCRIPTEN)
    add_executable(OasisC ${OasisC_SOURCES})
    set(CMAKE_EXECUTABLE_SUFFIX ".mjs")
    target_link_options(OasisC PUBLIC -sSINGLE_FILE --no-entry "-sEXPORT_NAME='OasisC'" "-sEXPORTED_RUNTIME_METHODS=ccall,cwrap")
else ()
    add_library(OasisC ${OasisC_SOURCES})
endif ()

target_include_directories(OasisC PUBLIC include)
target_link_libraries(OasisC PUBLIC Oasis::Oasis)

if(OASIS_BUILD_TESTS AND NOT DEFINED EMSCRIPTEN)
    add_subdirectory(tests)
endif()

if(OASIS_BUILD_EXTRAS)
    add_subdirectory(extras)
    if (DEFINED EMSCRIPTEN)
        target_link_libraries(OasisC PUBLIC OasisCExtras)
    endif ()
endif()