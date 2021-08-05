//
// Created by wwh on 2021/8/4.
//

#include "stack_common.h"

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
  if (pushed.empty() && popped.empty()) return true;

  std::stack<int> helper;

  for (int i = 0, j = 0; i < pushed.size(); ++i) {
    helper.push(pushed[i]);

    while (!helper.empty() && popped[j] == helper.top()) {
      helper.pop();
      ++j;
    }
  }

  return helper.empty();
}