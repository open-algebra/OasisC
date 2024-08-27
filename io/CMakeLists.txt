set(OasisC_IO_SOURCES
        # cmake-format: sortable
        src/FromString.cpp src/MathMLSerializer.cpp)

if (DEFINED EMSCRIPTEN)
    add_library(OasisCIO OBJECT ${OasisC_IO_SOURCES})
else ()
    add_library(OasisCIO ${OasisC_IO_SOURCES})
endif ()
    
target_include_directories(OasisCIO
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(OasisCIO PUBLIC Oasis::Oasis Oasis::IO)

if(OASIS_BUILD_TESTS)
    add_subdirectory(tests)
endif()
