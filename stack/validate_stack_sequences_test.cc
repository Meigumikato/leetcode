//
// Created by wwh on 2021/8/4.
//
#include <gtest/gtest.h>

#include "stack_common.h"

TEST(Stack, StackSeq) {
  std::vector<int> pushed = {1, 2, 3, 4, 5};
  std::vector<int> poped = {4, 5, 3, 2, 1};

  bool rst = validateStackSequences(pushed, poped);
  ASSERT_EQ(rst, true);

  poped = {4, 5, 3, 1, 2};

  rst = validateStackSequences(pushed, poped);

  ASSERT_EQ(rst, false);
}