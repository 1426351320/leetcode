//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <unordered_set>
#include <stack>
#include<functional>
#include <cstring>
#include<queue>

using namespace std;
class Solution 
{
public:
	bool hasPath(char* matrix, int rows, int cols, char* str);
	bool Search(vector<vector<int>> visit, int row, int column, char* str);
private:
	//vector<vector<int>>  Visit;
	vector<vector<int>> Map;
};
bool Solution::Search(vector<vector<int>> visit, int row, int column, char* str)
{
	if (Map[row][column] == *str)
	{
		if (*(str+1) == '\0')
			return true;
		visit[row][column] = 1;
		bool left(false), right(false), up(false), down(false);
		if (column + 1<Map[0].size() && !visit[row][column + 1])
			right = Search(visit, row, column + 1, str + 1);
		if (column - 1 >= 0&&!visit[row][column - 1])
			 left = Search(visit, row, column - 1, str + 1);
		if (row + 1<Map.size() && !visit[row + 1][column])
			down = Search(visit, row + 1, column, str + 1);
		if (row - 1>=0 && !visit[row - 1][column])
			 up = Search(visit, row-1, column , str + 1);

		if (left || right || up || down)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Solution::hasPath(char* matrix, int rows, int cols, char* str)
{
	for (int i(0); i < rows; i++)
	{
		Map.push_back(vector<int>{});
		for (int j(0); j < cols; j++)
			Map[i].push_back(matrix[i*cols + j]);
	}
	for (int i(0); i < rows; i++)
	{
		for (int j(0); j < cols; j++)
			if (Search(vector<vector<int>>(rows, vector<int>(cols, 0)), i, j, str))
				return true;
	}
	return false;
}

int main()
{
	//"AAAAAAAAAAAA",3,4,"AAAAAAAAAAAA"
	Solution sol;

	cout << sol.hasPath(const_cast<char*>("AAAAAAAAAAAA"),3,4, const_cast<char*>("AAAAAAAAAAAA"));




	return 0;
}
