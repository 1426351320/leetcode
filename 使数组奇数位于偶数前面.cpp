
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
	void reOrderArray(vector<int> &array);
};

void Solution::reOrderArray(vector<int> &array)
{
	int odd;
	for (int i(0); i < array.size(); i++)
	{
		if (!(array[i] & 1))
		{
			int j(i + 1);
			while ( j < array.size())
			{
				if (array[j] & 1)
				{
					odd = array[j];
					for (int k(j); k > i; k--)
						array[k] = array[k - 1];
					array[i] = odd;
					break;
				}
				j++;
			}
			if (j == array.size())
				break;
		}
	}
}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int> vec{ 1,2,3,4,5,6,7 };
	Sol.reOrderArray(vec);

	return 0;
}