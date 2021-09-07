#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  bool IsBalanced_Solution(TreeNode *pRoot);
  bool Depth(TreeNode *pRoot, int &depth);
};
bool Solution::IsBalanced_Solution(TreeNode *pRoot) {
  int redundant;
  return Depth(pRoot, redundant);
}
bool Solution::Depth(TreeNode *pRoot, int &depth) {
  if (pRoot == nullptr) {
    depth = 0;
    return true;
  }

  int left, right;
  if (Depth(pRoot->left, left) && Depth(pRoot->right, right)) {
    if (left - right <= 1 && left - right >= -1) {
      depth = 1 + max(left, right);
      return true;
    } else
      return false;
  }
  return false;
}

int main() {
  Solution Sol;

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->left = new TreeNode(7);

  cout << Sol.IsBalanced_Solution(root);

  return 0;
}
