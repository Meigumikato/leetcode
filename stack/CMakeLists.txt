cmake_minimum_required(VERSION 3.10)
project(stack)

include(GoogleTest)
enable_testing()
add_executable(validate_stack_sequences_test)
target_sources(validate_stack_sequences_test PRIVATE validate_stack_sequences.cc
                                                     validate_stack_sequences_test.cc)
target_link_libraries(validate_stack_sequences_test PRIVATE GTest::gtest_main)

