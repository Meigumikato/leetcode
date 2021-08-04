//
// Created by wwh on 2021/8/4.
//

#include "common.h"
#include <gtest/gtest.h>

TEST(S_D_test, check) {
    /* test tree
     *         1
     *        / \
     *       2   3
     *          / \
     *        4   5
     */


    TreeNode* root = new TreeNode(1);
    TreeNode* rl = new TreeNode(2);
    TreeNode* rr = new TreeNode(3);
    TreeNode* rrl = new TreeNode(4);
    TreeNode* rrr = new TreeNode(5);
    root->left = rl;
    root->right = rr;
    rr->left = rrl;
    rr->right = rrr;

    std::string rst = "1,2,3,#,#,4,5,#,#,#,#";
    std::string ret = serialize(root);
    EXPECT_EQ(rst, ret);

    std::vector<std::string> split_rst =
            {"1", "2", "3", "#","#","4","5","#","#","#","#"};
    std::vector<std::string> split_ret;
    Split(ret, split_ret);
    EXPECT_EQ(split_rst, split_ret);

    TreeNode* node_ret = deserialize(ret);
    ASSERT_NE(node_ret, nullptr);
    EXPECT_NE(node_ret, root);
    ASSERT_NE(node_ret->left, nullptr);
    EXPECT_EQ(node_ret->left->val, root->left->val);
    EXPECT_EQ(node_ret->right->val, root->right->val);

}



