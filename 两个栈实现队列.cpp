
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
	void push(int node) 
	{
		stack1.push(node);
	}

	int pop() 
	{
		int result;
		if (stack2.size() == 0)
		{
			while (stack1.size() !=0 )
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			result = stack2.top();
			stack2.pop();
		}
		else
		{
			result = stack2.top();
			stack2.pop();
		}
		return result;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
//"PSH1","PSH2","PSH3","POP","POP","PSH4","POP","PSH5","POP","POP"
int main(int argc, char *argv[])
{
	Solution Sol;
	Sol.push(1);
	Sol.push(2);
	Sol.push(3);
	Sol.pop();
	Sol.pop();
	Sol.push(4);
	Sol.pop();
	Sol.push(5);
	Sol.pop();
	Sol.pop();

	return 0;
}