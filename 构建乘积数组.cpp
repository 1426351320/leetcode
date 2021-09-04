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
	vector<int> multiply(const vector<int>& A);
};
vector<int> Solution::multiply(const vector<int>& A)
{
	deque<int> forward{ 1 }, backward{1};
	vector<int> result;
	for (int i(1); i < A.size(); i++)
		forward.push_back(forward.back()* A[i - 1]);
	for (int i(A.size()-2); i >=0; i--)
		backward.push_front(backward.front() * A[i + 1]);
	for (int i(0); i < A.size(); i++)
		result.push_back(forward[i] * backward[i]);
	return result;
}


int main()
{
	Solution Sol;
	vector<int> vec;
	vec = Sol.multiply(vector<int>{1, 2, 3});


	return 0;
}
