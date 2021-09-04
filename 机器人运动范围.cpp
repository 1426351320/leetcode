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
	int movingCount(int , int , int );
	int Search(vector<vector<int>>& , int , int);
	int BitSum(int, int);
private:
	int thr;
	int row, column;
};
int Solution::BitSum(int arg1, int arg2)
{
	int sum1(0), sum2(0);
	while (arg1)
	{
		sum1 += arg1 % 10;
		arg1 = arg1 / 10;
	}
	while (arg2)
	{
		sum2 += arg2 % 10;
		arg2 = arg2 / 10;
	}
	return sum1 + sum2;
}
int Solution::Search(vector<vector<int>>& visit, int y, int x)//y represents row and x represents columns
{
	if (BitSum(x,y) > thr)
		return 0;

	visit[y][x] = 1;

	int sum(1);
	if (x + 1<column && !visit[y][x + 1])
		sum += Search(visit, y, x + 1);
	if (x - 1 >= 0&&!visit[y][x - 1])
		sum += Search(visit, y, x - 1);
	if (y + 1<row && !visit[y + 1][x])
		sum += Search(visit, y + 1, x);
	if (y - 1>=0 && !visit[y - 1][x])
		sum += Search(visit, y-1, x);

	return sum;
}

int Solution::movingCount(int threshold, int rows, int cols)
{
	if (threshold <=0 )
		return 0;
	vector<vector<int>> visit(rows, vector<int>(cols, 0));
	thr = threshold;
	row = rows;
	column = cols;
	return Search(visit, 0, 0);
}

int main()
{
	Solution sol;
	cout << sol.movingCount(5, 10, 10);




	return 0;
}
