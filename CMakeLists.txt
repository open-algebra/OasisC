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
    set_target_properties(OasisC PROPERTIES SUFFIX ".mjs")
    target_link_libraries(OasisC PUBLIC embind)
    target_link_options(OasisC PUBLIC
            --no-entry
            "-sSINGLE_FILE"
            "-sEXPORT_NAME='useOasis'"
            "-sEXPORTED_RUNTIME_METHODS=ccall,cwrap"
            "-sENVIRONMENT='web'"
            "--emit-tsd OasisC.d.ts")
else ()
    add_library(OasisC ${OasisC_SOURCES})
endif ()

target_include_directories(OasisC PUBLIC include)
target_link_libraries(OasisC PUBLIC Oasis::Oasis)

if(OASIS_BUILD_TESTS AND NOT DEFINED EMSCRIPTEN)
    add_subdirectory(tests)
endif()

if(OASIS_BUILD_IO)
    add_subdirectory(io)
    if (DEFINED EMSCRIPTEN)
        target_link_libraries(OasisC PUBLIC OasisCIO)
    endif ()
endif()