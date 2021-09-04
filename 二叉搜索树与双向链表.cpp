
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


struct TreeNode 
{
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	TreeNode * Convert(TreeNode* pRootOfTree);
	void ConvertNode(TreeNode* pRootOfTree, TreeNode** LastMax);
};
TreeNode* Solution::Convert(TreeNode* pRootOfTree)
{
	TreeNode* LastMax(nullptr);
	ConvertNode(pRootOfTree, &LastMax);

	TreeNode* Head = pRootOfTree;
	while (Head->left&&Head!=nullptr)
		Head = Head->left;
	return Head;
}
void Solution::ConvertNode(TreeNode* pRootOfTree, TreeNode** LastMax)//中序遍历，将根节点与左链末端相连
{
	if (pRootOfTree==nullptr)
		return;

	TreeNode* Node(pRootOfTree);

	if(Node->left!=nullptr)
		ConvertNode(Node->left, LastMax);

	Node->left = *LastMax;
	if (*LastMax!=nullptr)
		(*LastMax)->right = Node;
		
	*LastMax = Node;

	if (Node->right!=nullptr)
		ConvertNode(Node->right, LastMax);
}


int main(int argc, char *argv[])
{
	Solution Sol;
	TreeNode* root = new TreeNode(10);
	root->left= new TreeNode(6);
	root->right = new TreeNode(14);
	root->left ->left= new TreeNode(4);
	root->left->right = new TreeNode(8);
	root->right ->left= new TreeNode(12);
	root->right->right = new TreeNode(16);
	
	TreeNode* list = Sol.Convert(root);

	return 0;
}







