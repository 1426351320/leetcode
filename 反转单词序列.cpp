//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	string ReverseSentence(string str);
	string Reverse(string str);
};
string Solution::Reverse(string str)
{
	int left(0), right(str.size() - 1);
	while (right > left)
	{
		char temp(str[left]);
		str[left] = str[right];
		str[right] = temp;
		left++;
		right--;
	}
	return str;
}
string Solution::ReverseSentence(string str)
{
	string WhollyReversed=Reverse(str);
	string Result;

	for (int i(0); i < WhollyReversed.size();)
	{
		if (WhollyReversed[i] == ' ')
			Result.push_back(WhollyReversed[i++]);
		else
		{
			string Temp;
			while (WhollyReversed[i] != ' '&&i<WhollyReversed.size())
				Temp.push_back(WhollyReversed[i++]);
			Result = Result + Reverse(Temp);
		}
	}

	return Result;
}

int main()
{
	Solution Sol;
	string str("world hello");

	cout << Sol.ReverseSentence(str);

	return 0;
}
