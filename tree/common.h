//
// Created by wwh on 2021/8/3.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* constructFromPrePost(std::vector<int>& pre, std::vector<int>& post);

std::string serialize(TreeNode* root);
void Split(const std::string& data, std::vector<std::string>& ret);
TreeNode* deserialize(std::string data);

#endif //LEETCODE_COMMON_H
