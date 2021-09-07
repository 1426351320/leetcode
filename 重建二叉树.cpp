#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin);
};

TreeNode *Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin) {
  if (pre.size() == 1)
    return new TreeNode(pre[0]);
  else if (pre.size() == 0)
    return nullptr;
  else {
    vector<int>::difference_type LeftNum, RightNum;
    vector<int>::iterator HeadPos;
    TreeNode *NewNode = new TreeNode(pre[0]);
    HeadPos = find(vin.begin(), vin.end(), pre[0]);
    LeftNum = HeadPos - vin.begin();
    RightNum = vin.end() - HeadPos - 1;
    NewNode->left = reConstructBinaryTree(
        vector<int>(pre.begin() + 1, pre.begin() + 1 + LeftNum),
        vector<int>(vin.begin(), HeadPos));
    NewNode->right =
        reConstructBinaryTree(vector<int>(pre.begin() + 1 + LeftNum, pre.end()),
                              vector<int>(HeadPos + 1, vin.end()));
    ;
    return NewNode;
  }
}

int main(int argc, char *argv[]) {
  vector<int> vec1{1, 2, 4, 7, 3, 5, 6, 8};
  vector<int> vec2{4, 7, 2, 1, 5, 3, 8, 6};
  Solution Sol;
  Sol.reConstructBinaryTree(vec1, vec2);

  return 0;
}