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

class Solution 
{
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size);
};

vector<int> Solution::maxInWindows(const vector<int>& num, unsigned int size)
{
	deque<int> MaxIndex;//最大值位置队列
	vector<int> Result;

	if (size > num.size()||!size)
		return Result;

	for (int i(0); i < num.size(); i++)
	{
		if (MaxIndex.size() == 0)
			MaxIndex.push_back(i);
		else if (num[i] <= num[MaxIndex.back()])
			MaxIndex.push_back(i);
		else
		{
			while (MaxIndex.size()&&num[i] > num[MaxIndex.back()])
				MaxIndex.pop_back();
			MaxIndex.push_back(i);
		}

		if (i - MaxIndex.front() >= size)
			MaxIndex.pop_front();

		if(i>=size-1)
			Result.push_back(num[MaxIndex.front()]);
	}
	return Result;
}

int main()
{

	Solution sol;
	vector<int> vec;
	vec = sol.maxInWindows(vector<int>{},3);


	return 0;
}
