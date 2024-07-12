FetchContent_Declare(
        munit
        GIT_REPOSITORY https://github.com/nemequ/munit
        GIT_TAG        master
)

FetchContent_MakeAvailable(munit)

add_library(munit ${munit_SOURCE_DIR}/munit.c)
target_include_directories(munit PUBLIC ${munit_SOURCE_DIR})