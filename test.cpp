
#include<iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include<unordered_map>


using namespace std;

class Solution 
{
public:
	void replaceSpace(char *str, int length);
};

void replaceSpace(char *str, int length)
{
	int SpaceNum(0);
	char *NewStr;
	for (int i(0); str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			SpaceNum++;
	}

	NewStr = new char[length + 2 * SpaceNum];

	for (int i(length-1);i>=0; i++)
	{
		if (str[i] == ' ')
		{
			NewStr[i + 2 * SpaceNum] = '0';
			NewStr[i + 2 * SpaceNum-1] = '2';
			NewStr[i + 2 * SpaceNum-2] = '%';
			SpaceNum--;
		}
		NewStr[i + 2 * SpaceNum] = str[i];
	}
	str = NewStr;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	char str[] = "happy new year";

	cout<<Sol.replaceSpace(str, 2);

	return 0;
}