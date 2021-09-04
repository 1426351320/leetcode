#include<iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
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
class Solution 
{
public:
	int TreeDepth(TreeNode* pRoot);
};
int Solution::TreeDepth(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 1;

	return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right))+1;
}
int main(int argc, char *argv[])
{
	Solution Sol;


	return 0;
}



