cmake_minimum_required(VERSION 3.0)

# 一定要在 project 指令之前
SET(CMAKE_C_COMPILER "/usr/bin/gcc-10")
SET(CMAKE_CXX_COMPILER "/usr/bin/g++-10")

set(CMAKE_CXX_STANDARD 20)

ENABLE_LANGUAGE( ASM)

project(flare C CXX)

set(CMAKE_VERBOSE_MAKEFILEON OFF)

set(CXX_FLAGS
  -g
  )

# set(CMAKE_CXX_LINKER_FLAGS "${CMAKE_CXX_LINKER_FLAGS} -Wl,--whole-archive")

find_package (glog 0.6.0 REQUIRED)
find_package(GTest REQUIRED)
find_package(fmt REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(yaml-cpp REQUIRED)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(flare/base)
add_subdirectory(flare/fiber)
add_subdirectory(flare/init)
add_subdirectory(flare/io)
add_subdirectory(flare/net)
add_subdirectory(flare/testing)
