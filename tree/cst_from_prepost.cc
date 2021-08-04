//
// Created by wwh on 2021/8/3.
//
#include "common.h"
using std::vector;

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {

    if (pre.empty() || post.empty()) return nullptr;
    int v_root = pre.front();
    TreeNode* root = new TreeNode(v_root);
    if (pre.size() == 1) return root;

    int loc = 0;

    // 寻找先序遍历左子数根节点在后续遍历中的位置
    for (; loc < post.size() ; ++loc) {
        if (post[loc] == pre[1])
            break;
    }
    // 根据确定的位置来在先序和后序 序列中划分左右子数

    // 左子树
    std::vector<int>left_pre(pre.begin() + 1, pre.begin() + 1 + loc + 1);
    std::vector<int>left_post(post.begin(), post.begin() + loc + 1);
    root->left = constructFromPrePost(left_pre, left_post);

    //右子树
    std::vector<int>right_pre(pre.begin() + 1 + loc + 1, pre.end());
    std::vector<int>right_post(post.begin() + loc + 1, post.end() - 1);
    root->right = constructFromPrePost(right_pre, right_post);

    return root;

}




