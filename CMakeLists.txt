cmake_minimum_required(VERSION 3.16)

project(ctci)

# set(CMAKE_C_COMPILER "/usr/bin/gcc")
# set(CMAKE_CXX_COMPILER "/usr/bin/g++")

if(DEBUG)
  set(CMAKE_C_FLAGS "-g -O0")
  set(CMAKE_CXX_FLAGS "-g -O0")
endif()

get_filename_component(
  PROJECT_ROOT
  "./"
  ABSOLUTE
)

get_filename_component(
  BUILD_OUTPUT_DIR
  "${PROJECT_ROOT}/build"
  ABSOLUTE
)


get_filename_component(
  CTCI
  "${PROJECT_ROOT}/ctci"
  ABSOLUTE
)

get_filename_component(
  LEETCODE
  "${PROJECT_ROOT}/leetcode"
  ABSOLUTE
)

add_subdirectory(ctci)

if(CPP_WITH_TEST)
  include(CTest)
  enable_testing()
  add_subdirectory(test)
endif()
