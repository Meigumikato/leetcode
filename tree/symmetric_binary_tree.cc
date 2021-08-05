//
// Created by wwh on 2021/8/4.
//

#include "common.h"

bool RecursiveHelper(TreeNode* nleft, TreeNode* nright) {
  if (nleft == nullptr && nright == nullptr) return true;
  if (nleft == nullptr || nright == nullptr || nleft->val != nright->val) return false;

  return RecursiveHelper(nleft->right, nright->left) && RecursiveHelper(nleft->left, nright->right);
}

bool isSymmetric(TreeNode* root) {
  if (root == nullptr) return true;

  return RecursiveHelper(root->left, root->right);
}
