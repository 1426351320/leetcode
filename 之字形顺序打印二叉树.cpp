//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <unordered_set>
#include <stack>
#include<functional>

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
	vector<vector<int> > Print(TreeNode* pRoot);
};

vector<vector<int> > Solution::Print(TreeNode* pRoot)
{
	stack<TreeNode*> stk1, stk2;
	vector<vector<int> > result;
	int flag(0);

	if (!pRoot)
		return result;
	
	stk1.push(pRoot);
	result.push_back(vector<int>());
	result[flag++].push_back(stk1.top()->val);

	while (stk1.size() != 0 || stk2.size() != 0)
	{
		result.push_back(vector<int>());
		if(flag%2)//从右向左
			while (stk1.size())
			{
				if (stk1.top()->right)
				{
					stk2.push(stk1.top()->right);
					result[flag].push_back(stk1.top()->right->val);
				}
				if (stk1.top()->left)
				{
					stk2.push(stk1.top()->left);
					result[flag].push_back(stk1.top()->left->val);
				}
				stk1.pop();
			}
		else//从左向右
			while (stk2.size())
			{
				if (stk2.top()->left)
				{
					stk1.push(stk2.top()->left);
					result[flag].push_back(stk2.top()->left->val);
				}
				if (stk2.top()->right)
				{
					stk1.push(stk2.top()->right);
					result[flag].push_back(stk2.top()->right->val);
				}
				stk2.pop();
			}
		flag++;
	}
	result.pop_back();
	return result;
}

int main()
{
	Solution Sol;

	TreeNode* Node = new TreeNode(1);
	Node->left= new TreeNode(2);
	Node->right = new TreeNode(3);
	Sol.Print(Node);
	


	return 0;
}
