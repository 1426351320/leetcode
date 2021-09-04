
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
	bool searchMatrix(vector<vector<int>>& matrix, int target);
};

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target)
{
	int row(0);
	int column(INT_MAX);
	if (matrix.size() != 0)
	{
		row = 0;
		column=matrix[0].size() - 1;
	}
	else
		return false;

	while (row < matrix.size() && column >= 0)
	{
		if (matrix[row][column] > target)
			column--;
		else if (matrix[row][column] < target)
			row++;
		else
			return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<vector<int>> vec{ vector<int>{1} };
	cout<<Sol.searchMatrix(vec, 2);

	return 0;
}