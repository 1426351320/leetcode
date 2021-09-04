//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <unordered_set>
#include<functional>

using namespace std;


struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};

class Solution 
{
public:
	TreeLinkNode * GetNext(TreeLinkNode* pNode);
};

TreeLinkNode * Solution::GetNext(TreeLinkNode* pNode)
{
	if (!pNode)
		return pNode;
	TreeLinkNode* Node(pNode->right);

	//有右子树
	if (Node != nullptr)
	{
		while (Node->left != nullptr)
			Node = Node->left;
		return Node;
	}

	//无右子树，且是父节点的左孩子
	if (pNode->next!=nullptr&&pNode->next->left == pNode)
		return pNode->next;

	//无右子树，且不是父节点的左孩子
	Node = pNode;
	while (Node != nullptr)
	{
		if (Node->next != nullptr)
			if (Node->next->left == Node)
				return Node->next;
		Node = Node->next;
	}
	return Node;
}


int main()
{
	Solution Sol;
	TreeLinkNode* Node = new TreeLinkNode(1);
	Node->next= new TreeLinkNode(2); 
	Node->next->right = Node;
	Node->left = new TreeLinkNode(3);
	Node->left->next = Node;
	//Node->right = new TreeLinkNode(4);
	//Node->right->next = Node;

	Sol.GetNext(Node);

	


	return 0;
}
