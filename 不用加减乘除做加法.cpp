//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution 
{
public:
	int Add(int num1, int num2);
};
int Solution::Add(int num1, int num2)
{
	int Carry(INT_MAX);
	int Sum;
	while (Carry)
	{
		Sum = num1 ^ num2;
		Carry = (num1&num2) << 1;
		num1 = Carry;
		num2 = Sum;
	}
	return Sum;
}

int main()
{
	Solution Sol;

	cout << Sol.Add(6, 4);

	return 0;
}
