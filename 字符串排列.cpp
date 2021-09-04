
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

class Solution {
public:
	vector<string> Permutation(string str);
	void Permutation(string str,int pos);
private:
	vector<string> vec;
};
void Solution::Permutation(string str, int pos)
{
	if (pos == str.size() - 1)
	{
		vec.push_back(str);
		return;
	}
		
	for (int i(pos); i < str.size(); i++)
	{
		if (str[i] == str[pos] && i > pos)
			continue;

		char temp(str[pos]);
		str[pos] = str[i];
		str[i] = temp;
		Permutation(str, pos + 1);
		str[i] = str[pos];
		str[pos] = temp;
	}
}
bool comp(const string& str1, const string& str2)
{
	if (str1.compare(str2) >= 0)
		return false ;
	else
		return true;
}
vector<string> Solution::Permutation(string str)
{
	if (str.size() == 0)
		return vec;


	Permutation(str, 0);
	sort(vec.begin(), vec.end(), comp);

	return vec;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<string> vec;
	vec = Sol.Permutation("abc");



	return 0;
}







