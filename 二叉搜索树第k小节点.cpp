//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <unordered_set>
#include <stack>
#include<functional>
#include <cstring>
#include<queue>

using namespace std;




struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Solution {
public:
	TreeNode * KthNode(TreeNode* pRoot, int k);
	TreeNode* PreOrder(TreeNode* pRoot);
private:
	int count;
};

TreeNode* Solution::PreOrder(TreeNode* pRoot)
{
	TreeNode* Node;
	if (!pRoot)
		return nullptr;

	Node = PreOrder(pRoot->left);
	if (Node)
		return Node;
	if (count == 1)
		return pRoot;

	count--;
	Node = PreOrder(pRoot->right);
	return Node;
}

TreeNode* Solution::KthNode(TreeNode* pRoot, int k)
{
	count = k;
	return PreOrder(pRoot);
}


int main()
{
	Solution Sol;
	TreeNode *Node = new TreeNode(8);
	Node->left = new TreeNode(6);
	Node->left ->left= new TreeNode(5);
	Node->left->right = new TreeNode(7);
	Node->right = new TreeNode(10);
	Node->right->left = new TreeNode(9);
	Node->right->right = new TreeNode(11);
	TreeNode *newnode=Sol.KthNode(Node,1);



	return 0;
}
