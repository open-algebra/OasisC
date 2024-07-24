set(OasisC_EXTRAS_SOURCES
        # cmake-format: sortable
        src/FromString.cpp src/MathMLSerializer.cpp)

if (DEFINED EMSCRIPTEN)
    add_library(OasisCExtras OBJECT ${OasisC_EXTRAS_SOURCES})
else ()
    add_library(OasisCExtras ${OasisC_EXTRAS_SOURCES})
endif ()
    
target_include_directories(OasisCExtras
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(OasisCExtras PUBLIC Oasis::Oasis Oasis::Extras)

if(OASIS_BUILD_TESTS)
    add_subdirectory(tests)
endif()
