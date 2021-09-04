//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum);
};
vector<vector<int> > Solution::FindContinuousSequence(int sum)
{
	int start(1), end(2);
	vector < vector<int>> result;
	while (start<end)
	{
		int temp = (start + end)*(end - start + 1) / 2;
		if (temp == sum)
		{
			vector<int> tempvec;
			for (int i(start); i <= end; i++)
				tempvec.push_back(i);
			result.push_back(tempvec);
			end++;
		}
		else if (temp > sum)
			start++;
		else if(temp <sum)
			end++;
	}
	return result;
}

int main()
{
	Solution Sol;
	Sol.FindContinuousSequence(15);





	return 0;
}
