//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	int StrToInt(string str);
};

int Solution::StrToInt(string str)
{
	int result(0);
	int sign(1);
	if (str[0] == '+')
	{
		sign = 1;
		str.erase(str.begin());
	}
	else if (str[0] == '-')
	{
		sign = -1;
		str.erase(str.begin());
	}

	for (int i(0); i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
		else
			result = result + (str[i] - '0')*pow(10, str.size()-1-i);
	}
	result = result * sign;

	return result;
}

int main()
{
	Solution Sol;




	return 0;
}
