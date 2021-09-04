//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m);
};
int Solution::LastRemaining_Solution(int n, int m)
{
	vector<int> kids;
	if (n <= 0||m<=0)
		return -1;

	for (int i(0); i < n; i++)
		kids.push_back(i);
	int start(0);
	while (kids.size() > 1)
	{
		start = (start + m-1) % kids.size();
		kids.erase(kids.begin()+start);
	}
	return kids.front();
}

int main()
{
	Solution Sol;


	cout<<Sol.LastRemaining_Solution(0, 8);



	return 0;
}
