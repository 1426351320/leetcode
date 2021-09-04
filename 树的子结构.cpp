
#include<iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <unordered_map>


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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
	bool Judge(TreeNode* pRoot1, TreeNode* pRoot2);
};
bool Solution::Judge(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == nullptr)
		return true;
	else if (pRoot1 == nullptr)
		return false;
	
	if (pRoot1->val != pRoot2->val)
		return false;
	if (!Judge(pRoot1->left, pRoot2->left))
		return false;
	if (!Judge(pRoot1->right, pRoot2->right))
		return false;

	return true;
}

bool Solution::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	//ÖÐÐò±éÀú
	if (pRoot1->val == pRoot2->val)
		if (Judge(pRoot1, pRoot2))
			return true;
	if (HasSubtree(pRoot1->left, pRoot2))
		return true;
	if (HasSubtree(pRoot1->right, pRoot2))
		return true;

	return false;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	TreeNode* root = new TreeNode(8);
	TreeNode* SubTree = new TreeNode(8);

	SubTree->left = new TreeNode(9);
	SubTree->right = new TreeNode(2);

	root->left = new TreeNode(8);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(9);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(4);
	root->left->right->right = new TreeNode(7);
	cout << Sol.HasSubtree(root, SubTree);

	return 0;
}