include(FetchContent)
include(cmake/FetchMUnit.cmake)

add_executable(OasisCTests main.c)
target_link_libraries(OasisCTests PUBLIC OasisC munit)