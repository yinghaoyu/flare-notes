cmake_minimum_required(VERSION 3.0)

# 一定要在 project 指令之前
SET(CMAKE_C_COMPILER "/usr/bin/gcc-10")
SET(CMAKE_CXX_COMPILER "/usr/bin/g++-10")

set(CMAKE_CXX_STANDARD 20)

project(flare C CXX)

set(CXX_FLAGS
  -g
  )

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(flare/base)