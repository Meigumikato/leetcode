cmake_minimum_required(VERSION 3.10)
project(tree)
enable_testing()

add_executable(serialize_and_deserialize_test)
target_include_directories(serialize_and_deserialize_test PUBLIC
                            ${ROOT_DIR})
target_sources(serialize_and_deserialize_test PRIVATE
                common.h
                serialize_and_deserialize.cc
                serialize_and_deserialize_test.cc)
target_link_libraries(serialize_and_deserialize_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(serialize_and_deserialize_test)