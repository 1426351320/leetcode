//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum);
};
vector<int> Solution::FindNumbersWithSum(vector<int> array, int sum)
{
	int start(0), end(array.size() - 1);
	vector<int> result;
	while (end > start)
	{
		if (sum == array[start] + array[end])
		{
			if (result.size() == 0)
			{
				result.push_back(array[start]);
				result.push_back(array[end]); 
			}
			else if (result[0] * result[1] > array[start] * array[end])
			{
				result[0]=array[start];
				result[1]=array[end];
			}
			end--;
		}
		else if (sum > array[start] + array[end])
			start++;
		else if (sum < array[start] + array[end])
			end--;
	}
	return result;
}

int main()
{
	Solution Sol;
	
	Sol.FindNumbersWithSum(vector<int>{1, 2, 4, 7, 11, 15},15);




	return 0;
}
