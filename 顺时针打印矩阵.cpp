
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

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix);
};
vector<int> Solution::printMatrix(vector<vector<int> > matrix) 
{
	int left(0), right(matrix[0].size()-1), top(0), bottom(matrix.size()-1);
	vector<int> result;
	while (left <= right && top <= bottom)
	{
		if (right>=left)
			for (int i(left); i <= right; i++)//左到右
				result.push_back(matrix[top][i]);

		if (bottom>=top)
			for (int i(top+1); i <= bottom ; i++)//上到下
				result.push_back(matrix[i][right]); 

		if(right>=left&& bottom > top)
			for (int i(right-1); i >= left ; i--)//右到左
				result.push_back(matrix[bottom][i]);

		if (bottom >= top&& right > left)
			for (int i(bottom-1); i >= top+1 ; i--)//下到上
				result.push_back(matrix[i][left]);

		left++;
		right--;
		top++;
		bottom--;
	}
	return result;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<vector<int>> vec{ vector<int> {1},vector<int> {2},vector<int> {3}, vector<int> { 4},vector<int> { 5} };
	vector<int> vec1=Sol.printMatrix(vec);



	return 0;
}