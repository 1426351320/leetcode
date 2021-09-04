
#include<iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>


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
	vector<int> PrintFromTopToBottom(TreeNode* root);
};

vector<int> Solution::PrintFromTopToBottom(TreeNode* root)
{
	vector<int> result;
	queue<TreeNode*> NodeQue;

	if (root == nullptr)
		return result;

	NodeQue.push(root);

	while (NodeQue.size())
	{
		if(NodeQue.front()->left)
			NodeQue.push(NodeQue.front()->left);
		if (NodeQue.front()->right)
			NodeQue.push(NodeQue.front()->right);

		result.push_back(NodeQue.front()->val);
		NodeQue.pop();
	}

	return result;
}

//4, 3, 5, 1, 2
int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int> vec;
	TreeNode* root=new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	vec=Sol.PrintFromTopToBottom(root);

	return 0;
}