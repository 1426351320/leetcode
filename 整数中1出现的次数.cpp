
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
	int NumberOf1Between1AndN_Solution(int n);
	int pow(int arg1, int arg2)
	{
		int temp = arg2;
		int result(1);

		if (!arg2)
			return 1;

		while (temp > 0)
		{
			result *= 10;
			temp--;
		}
		return result;
	}
};
int Solution::NumberOf1Between1AndN_Solution(int n)
{
	int sum(0);
	int count(0);
	while (n / pow(10, count))
		count++;

	for (; count >= 1; count--)
	{
		int temp = (n / pow(10, count - 1)) % 10;
		if (temp > 1)
			sum += (n / pow(10, count) + 1)*pow(10, count - 1);
		else if(temp == 1)
			sum += (n / pow(10, count))*pow(10, count - 1)+n%pow(10,count-1)+1;
		else if(temp<1)
			sum += (n / pow(10, count))*pow(10, count - 1);
	}
	return sum;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int > vec{ 1,-2,3,10,-4,7,2,-5 };

	cout << Sol.NumberOf1Between1AndN_Solution(2134);
	return 0;
}







