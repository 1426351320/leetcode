//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
	bool match(char* str, char* pattern);
};

bool Solution::match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;

	if (*str == '\0'&&*pattern == '\0')
		return true;
	else if (*str != '\0'&&*pattern == '\0')
		return false;
	
	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.'&&*str != '\0'))
			return match(str + 1, pattern + 2) || match(str+1, pattern) || match(str, pattern + 2);
		else
			return match(str, pattern + 2);
	}
	if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
		return match(str + 1, pattern + 1);

	return false;
}

int main()
{
	Solution Sol;
	char str1[] = { "aa\0" };
	char str2[] = { "a*\0" };
	cout << Sol.match(str1,str2);


	return 0;
}
