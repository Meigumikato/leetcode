//
// Created by wwh on 2021/8/3.
//
#include <cstring>
#include <iostream>
#include <queue>

#include "common.h"

using std::string;
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
  if (root == nullptr) return "";

  string ret = std::to_string(root->val);

  std::queue<TreeNode*> Bfs;
  // 根节点推入队列，开始广度优先遍历
  Bfs.push(root);

  for (int len = Bfs.size(); len > 0; len = Bfs.size()) {
    while (len > 0) {
      if (Bfs.front() == nullptr) {
        Bfs.pop();
        continue;
      }

      if (Bfs.front()->left != nullptr) {
        Bfs.push(Bfs.front()->left);
        ret.append(",");
        ret.append(std::to_string(Bfs.front()->left->val));
      } else
        ret.append(",#");

      if (Bfs.front()->right != nullptr) {
        Bfs.push(Bfs.front()->right);
        ret.append(",");
        ret.append(std::to_string(Bfs.front()->right->val));
      } else
        ret.append(",#");
      Bfs.pop();
      --len;
    }
  }

  return ret;
}

void Split(const string& data, std::vector<std::string>& ret) {
  if (data.empty()) return;
  int len_data = data.size();
  int begin_loc = 0, i = 0;

  while (i < len_data) {
    if (data[i] != ',') {
      ++i;
    } else {
      ret.emplace_back(data.begin() + begin_loc, data.begin() + i);
      ++i;
      begin_loc = i;
    }
  }

  ret.emplace_back(data.begin() + begin_loc, data.begin() + i);
}

int MyAtoi(const char* str) {
  //    if (str == nullptr)
  //        return 0;
  //    size_t size = strlen(str);
  //    int ret = 0;
  //    size_t i = size;
  //    while(i >= 0) {
  //        if (str[i] <= '9' && str[i] >= '0'){
  //          i += (str[i] - '0') * ()
  //        }
  //        else {
  //
  //        }
  //        --i;
  //    }
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
  if (data.empty()) return nullptr;

  std::vector<std::string> split_arr;

  Split(data, split_arr);

  std::queue<TreeNode*> helper_queue;
  TreeNode* root = new TreeNode(atoi(split_arr[0].c_str()));
  helper_queue.push(root);

  int i = 1;

  while (i < split_arr.size()) {
    if (split_arr[i] != "#") {
      TreeNode* nleft = new TreeNode(atoi(split_arr[i].c_str()));
      helper_queue.front()->left = nleft;
      helper_queue.push(nleft);
    }

    ++i;

    if (split_arr[i] != "#") {
      TreeNode* nright = new TreeNode(atoi(split_arr[i].c_str()));
      helper_queue.front()->right = nright;
      helper_queue.push(nright);
    }

    ++i;
    helper_queue.pop();
  }

  return root;
}
