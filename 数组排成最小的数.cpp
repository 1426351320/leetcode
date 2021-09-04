
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

class Solution 
{
public:
	string PrintMinNumber(vector<int> numbers);
};
bool comp(const string arg1, const string arg2)
{
	string temp1(arg1 + arg2), temp2(arg2 + arg1);

	if (temp1.compare(temp2) <= 0)
		return true;
	else
		return false;
}
string Solution::PrintMinNumber(vector<int> numbers)
{
	vector<string> str;
	for (int i(0); i < numbers.size(); i++)
	{
		stringstream ss;
		ss << numbers[i];
		str.push_back(ss.str());
	}
	sort(str.begin(),str.end(),comp);

	string result;
	for (int i(0); i < str.size(); i++)
		result += str[i];
	return result;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int> vec{ 24,10 };
	cout<<Sol.PrintMinNumber(vec);


	return 0;
}







