
#include<iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <queue>


using namespace std;

class Solution {
public:
	long long GetUglyNumber_Solution(int index);
};
long long Solution::GetUglyNumber_Solution(int index)
{
	if (index == 0)
		return 0;

	vector<long long> UglyNum{ 1 };//保存丑数
	long long MaxUgly(1);
	int T2(0), T3(0), T5(0);//Tn是乘以n后大于最大丑数的第一个值的位置
	while (UglyNum.size() < index)
	{
		for (int i(T2); i < UglyNum.size(); i++)
		{
			if ((UglyNum[i] * 2) <= MaxUgly)
				T2++;
		}

		for (int i(T3); i < UglyNum.size(); i++)
		{
			if ((UglyNum[i] * 3) <= MaxUgly)
				T3++;
		}

		for (int i(T5); i < UglyNum.size(); i++)
		{
			if ((UglyNum[i] * 5) <= MaxUgly)
				T5++;
		}
		vector<long long> temp{ UglyNum[T2] * 2,UglyNum[T3] * 3,UglyNum[T5] * 5 };
		sort(temp.begin(), temp.end());
		MaxUgly = temp[0];
		UglyNum.push_back(temp[0]);
	}
	return UglyNum.back();
}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int> vec{ 24,10 };
	
	cout<<Sol.GetUglyNumber_Solution(1500);

	return 0;
}







