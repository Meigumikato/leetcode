cmake_minimum_required(VERSION 3.10)

project(leetcode)
set(CMAKE_CXX_STANDARD 17)
set(ROOT_DIR ${PROJECT_SOURCE_DIR})
#Gtest
set (GTest_DIR ${CMAKE_SOURCE_DIR}/third_party/googletest/build/installed/lib/cmake/GTest)
find_package(GTest REQUIRED)

add_subdirectory(tree)
add_subdirectory(list)
add_subdirectory(stack)