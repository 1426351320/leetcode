//C:\Users\���ϵ���ʷ\OneDrive\Documents\��̨����\��ĿԴ��

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

	//��������
	if (Node != nullptr)
	{
		while (Node->left != nullptr)
			Node = Node->left;
		return Node;
	}

	//�������������Ǹ��ڵ������
	if (pNode->next!=nullptr&&pNode->next->left == pNode)
		return pNode->next;

	//�����������Ҳ��Ǹ��ڵ������
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
