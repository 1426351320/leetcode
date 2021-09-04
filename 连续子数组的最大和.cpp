
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

class Solution 
{
public:
	int FindGreatestSumOfSubArray(vector<int> array);
};
int Solution::FindGreatestSumOfSubArray(vector<int> array)
{
	if (array.size() == 0)
		return 0;
	vector<int> dp(2,0);
	int result= array[0];
	dp[0] = array[0];

	for (int i(1); i < array.size(); i++)
	{
		if (dp[(i + 1) % 2]<=0)
			dp[i % 2] = array[i];
		else
			dp[i % 2] = array[i]+ dp[(i + 1) % 2];
		result = max(result,dp[i%2]);
	}
	return result;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int > vec{ 1,-2,3,10,-4,7,2,-5 };
	cout << Sol.FindGreatestSumOfSubArray(vec);

	return 0;
}







