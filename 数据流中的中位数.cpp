//C:\Users\���ϵ���ʷ\OneDrive\Documents\��̨����\��ĿԴ��

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
	void Insert(int num);
	int BS(int arg);//������������λ��
	double GetMedian();
private:
	vector<int> vec;//�������е�����
};
int Solution::BS(int arg)//����Ҫ�����λ��
{
	int left(0), right(vec.size()-1),mid((left + right)/2);
	while (right > left)
	{
		if (vec[mid] >= arg)
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else if (vec[mid] < arg)
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
	}
	return mid;
}
void Solution::Insert(int num)
{
	if (vec.size() == 0)
	{
		vec.push_back(num);
		return;
	}
	int pos = BS(num);
	
	if (num >= vec[pos])
		vec.insert(vec.begin()+pos+1,num);
	else
		vec.insert(vec.begin() + pos, num);
}
double Solution::GetMedian()
{
	if (!vec.size())
		return 0;
	if (vec.size() % 2)
		return vec[vec.size() / 2];
	else
		return (static_cast<double>(vec[vec.size() / 2]) + static_cast<double>(vec[vec.size() / 2 - 1]))/2;
}

int main()
{
	//5,2,3,4,1,6,7,0,8
	Solution sol;
	sol.Insert(5);
	sol.Insert(2);
	sol.Insert(3);
	sol.Insert(4);
	sol.Insert(1);
	sol.Insert(6);
	sol.Insert(7);
	sol.Insert(0);
	sol.Insert(8);


	return 0;
}
