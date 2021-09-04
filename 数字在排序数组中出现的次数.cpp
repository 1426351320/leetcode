#include<iostream>
#include <vector>
#include <stdexcept>
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
	int GetNumberOfK(vector<int> data, int k);
};
int Solution::GetNumberOfK(vector<int> data, int k)
{
	if (!data.size())
		return 0;

	int left(0), right(data.size() - 1), first(data.size() / 2);
	while (1)
	{
		if (data[first] > k)
		{
			right = first - 1;
			first = (right + left) / 2;
		}
		else if (data[first] < k)
		{
			left = first + 1;
			first = (right + left) / 2;
		}
		else if (data[first] == k)
		{
			if (!first)
				break;
			if (data[first - 1] != k)
				break;
			else
			{
				right = first - 1;
				first = (right + left) / 2;
			}
		}
		if (right < left)
			return 0;
	}
	right = data.size() - 1;
	left = first;
	int last = (left + right) / 2;
	while (1)
	{
		if (data[last] > k)
		{
			right = last - 1;
			last = (right + left) / 2;
		}
		else if (data[last] < k)
		{
			left = last + 1;
			last = (right + left) / 2;
		}
		else if (data[last] == k)
		{
			if (last == data.size() - 1)
				break;
			if (data[last + 1] != k)
				break;
			else
			{
				left = last + 1;
				last = (right + left) / 2;
			}
		}
		if (right < left)
			return 0;
	}
	return last - first + 1;
}
int main(int argc, char *argv[])
{
	Solution Sol;


	return 0;
}