//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <unordered_set>
#include<functional>

using namespace std;


class comp
{
public:
	comp(char arg) :ch(arg) {}
	bool operator() (pair<char,int> arg)
	{
		return arg.first == ch;
	}
private:
	char ch;
};
class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch);
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce();
private:
	vector<pair<char, int>> Index;
};
void Solution::Insert(char ch)
{
	auto Ite = find_if(Index.begin(), Index.end(), comp(ch));
	if (Ite != Index.end())
		Ite->second++;
	else
		Index.push_back(make_pair(ch, 1));
}
char Solution::FirstAppearingOnce()
{
	char ch = '#';
	for (auto ite = Index.begin(); ite != Index.end(); ite++)
	{
		if (ite->second == 1)
		{
			ch = ite->first;
			break;
		}	
	}
	return ch;
}


int main()
{
	Solution Sol;
	vector<int> vec{ 1,4,2,6,3,5,1,3,2,0 };

	Sol.Insert('g');
	cout<<Sol.FirstAppearingOnce();
	Sol.Insert('o');
	cout << Sol.FirstAppearingOnce();
	Sol.Insert('o');
	cout << Sol.FirstAppearingOnce();
	Sol.Insert('g');
	cout << Sol.FirstAppearingOnce();
	Sol.Insert('l');
	cout << Sol.FirstAppearingOnce();
	Sol.Insert('e');
	cout << Sol.FirstAppearingOnce();
	return 0;
}
