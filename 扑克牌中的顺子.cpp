//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers);
};

bool Solution::IsContinuous(vector<int> numbers)
{
	if (numbers.size() == 0)
		return false;
	sort(numbers.begin(), numbers.end());
	int ZeroNum = count(numbers.begin(), numbers.end(),0);
	if (ZeroNum == 4)
		return true;

	for (int i(ZeroNum+1); i < numbers.size(); i++)
	{
		int diff = numbers[i] - numbers[i - 1];
		if (diff > 1)
			ZeroNum = ZeroNum - (diff - 1);
		else if (diff == 0)
			return false;
		if (ZeroNum < 0)
			return false;
	}
	return true;
}

int main()
{
	Solution Sol;






	return 0;
}
