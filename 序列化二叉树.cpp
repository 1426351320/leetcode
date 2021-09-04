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

class Solution 
{
public:
	char* Serialize(TreeNode *root);//前序遍历
	TreeNode* Deserialize(char* &str);
};

char* Solution::Serialize(TreeNode *root)
{
	if (!root)
	{
		char *str = new char[2]{'#','\0'};
		return str;
	}
	char *left = Serialize(root->left);
	char *right = Serialize(root->right);
	char *str = new char[2];
	str[0]=root->val+'0';
	str[1] = '\0';
	strcat_s(str, strlen(str) + strlen(left) + 1, left);
	strcat_s(str, strlen(str) + strlen(right) + 1, right);
	return str;
}
TreeNode* Solution::Deserialize(char* &str)
{
	if(str[0]=='#')
		return nullptr;
	TreeNode* Node = new TreeNode(str[0]-'0');
	Node->left = Deserialize(++str );
	Node->right= Deserialize(++str);
	return Node;
}

int main()
{
	Solution Sol;
	TreeNode *Node = new TreeNode(1);
	Node->left = new TreeNode(2);
	Node->left ->left= new TreeNode(4);
	Node->right = new TreeNode(3);
	Node->right->left = new TreeNode(5);
	Node->right->right = new TreeNode(6);

	char * output=Sol.Serialize(Node);
	TreeNode *Reconstruct=Sol.Deserialize(output);


	return 0;
}
