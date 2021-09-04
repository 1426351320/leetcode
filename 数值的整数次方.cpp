
#include<iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <unordered_map>


using namespace std;

class Solution 
{
public:
	double Power(double base, int exponent);
};

double Solution::Power(double base, int exponent)
{
	double result(base);
	if (!exponent)
		return 1;
	else if (exponent < 0)
	{
		if (base == 0)
			throw(string("error!"));
		while (-exponent>1)
		{
			result *= base;
			exponent++;
		}
		result = 1 / result;
	}
	else if (exponent > 0)
	{
		while (exponent>1)
		{
			result *= base;
			exponent--;
		}
	}
	return result;
}


int main(int argc, char *argv[])
{
	Solution Sol;
	cout << Sol.Power(0,-3);

	return 0;
}