
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

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int size = sequence.size();
		if (0 == size)return false;

		int i = 0;
		while (--size)
		{
			while (sequence[i++]<sequence[size]);
			while (sequence[i++]>sequence[size]);

			if (i<size)return false;
			i = 0;
		}
		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int> vec;
	//TreeNode* root=new TreeNode(1);
	//root->left = new TreeNode(2);
	//root->right = new TreeNode(3);
	//root->left->left = new TreeNode(4);
	//root->left->right = new TreeNode(5);
	//root->right->left = new TreeNode(6);
	//vec=Sol.PrintFromTopToBottom(root);
	cout << Sol.VerifySquenceOfBST(vector<int>{5,7,6,9,11,10,8});

	return 0;
}