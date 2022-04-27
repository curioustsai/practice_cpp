cmake_minimum_required(VERSION 3.16)

project(ctci)

# set(CMAKE_C_COMPILER "/usr/bin/gcc")
# set(CMAKE_CXX_COMPILER "/usr/bin/g++")

if(DEBUG)
    set(CMAKE_C_FLAGS "-g -O0")
    set(CMAKE_CXX_FLAGS "-g -O0")
endif()

get_filename_component(PROJECT_ROOT "./" ABSOLUTE)

get_filename_component(BUILD_OUTPUT_DIR "${PROJECT_ROOT}/build" ABSOLUTE)

get_filename_component(CTCI "${PROJECT_ROOT}/ctci" ABSOLUTE)

get_filename_component(LEETCODE "${PROJECT_ROOT}/leetcode" ABSOLUTE)

### GoogleTest ###
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

### Env ###
list(APPEND CMAKE_MODULE_PATH ${PROJECT_ROOT}/cmake)
include(${CMAKE_MODULE_PATH}/utils/Utils.cmake)

add_subdirectory(code)
