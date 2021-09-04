
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
	int FirstNotRepeatingChar(string str);
};
bool comp(pair<char, size_t> arg1, pair<char, size_t> arg2)
{
	return arg1.second < arg2.second;
}

int Solution::FirstNotRepeatingChar(string str)
{
	multimap<char, size_t> Index;
	vector<pair<char, size_t>> Result;
	for (size_t i(0); i < str.size(); i++)
		Index.insert(make_pair(str[i], i));

	for (multimap<char, size_t>::iterator ite = Index.begin(); ite != Index.end(); )
	{
		if (Index.count(ite->first) == 1)
			Result.push_back(*ite);
		ite = Index.upper_bound(ite->first);
	}
	sort(Result.begin(), Result.end(), comp);

	if (Result.size() == 0)
		return -1;

	return Result.begin()->second;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	cout << Sol.FirstNotRepeatingChar("aodifhaindfoiauwnefoildiunhiwetg");

	return 0;
}