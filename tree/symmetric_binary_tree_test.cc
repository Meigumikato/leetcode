//
// Created by wwh on 2021/8/4.
//

#include <gtest/gtest.h>

#include "common.h"

TEST(BinaryTree, Symmetric) {
  TreeNode* root = nullptr;
  bool ret = isSymmetric(root);
  ASSERT_EQ(ret, true);
}
