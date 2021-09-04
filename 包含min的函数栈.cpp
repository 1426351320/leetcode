
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

class Solution {
public:
	void push(int value) 
	{
		stk1.push(value);
		if (stk2.size())
		{
			if (value < stk2.top())
				stk2.push(value);
			else
				stk2.push(stk2.top());
		}
		else
			stk2.push(value);
	}
	void pop() 
	{
		stk1.pop();
		stk2.pop();
	}
	int top() 
	{
		return stk1.top();
	}
	int min() 
	{
		return stk2.top();
	}
private:
	stack<int,vector<int>> stk1, stk2;
};

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int > vec{ 1,4,2,6,3,5,1,3,2,0 };
	for (int i(0); i < vec.size(); i++)
		Sol.push(vec[i]);
	
	cout<<Sol.min();

	return 0;
}