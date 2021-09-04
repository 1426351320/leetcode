
#include<iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>


using namespace std;

class Solution 
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers);
//	int Partition(vector<int>& arg1, int begin, int end);
};
int Solution::MoreThanHalfNum_Solution(vector<int> numbers)
{
	int num(numbers[0]), times(1);
	for (int i(1); i < numbers.size(); i++)
	{
		if (times == 0)
		{
			num = numbers[i];
			times = 1;
		}
		if (num != numbers[i])
			times--;
		else if (num == numbers[i])
			times++;
	}

	int count(0);
	for (int i(0); i < numbers.size(); i++)
	{
		if (numbers[i] == num)
			count++;
	}
	if (count <= numbers.size() / 2)
		return 0;
	else
		return num;
}
//int Solution::MoreThanHalfNum_Solution(vector<int> numbers)
//{
//	if (numbers.size() == 0)
//		return 0;
//
//	int middle=Partition(numbers, 0, numbers.size()-1);
//	int left(0), right(numbers.size() - 1);
//
//	while (middle != numbers.size() / 2)
//	{
//		if (middle > numbers.size() / 2)
//		{
//			right = middle-1;
//			middle	=	Partition(numbers, left, right);
//		}
//			
//		if (middle < numbers.size() / 2)
//		{
//			left = middle+1;
//			middle = Partition(numbers, left, right);
//		}
//	}
//
//	int result = numbers[middle];
//	int count(0);
//	for (int i(0); i < numbers.size(); i++)
//	{
//		if (numbers[i] == result)
//			count++;
//	}
//	if (count <= numbers.size() / 2)
//		return 0;
//	else
//		return result;
//}
//int Solution::Partition(vector<int>& arg1, int begin, int end)
//{
//	int i(begin - 1), j(begin);
//	while (j <= end - 1)
//	{
//		if (arg1[j] <= arg1[end])
//		{
//			i++;
//			int temp = arg1[i];
//			arg1[i] = arg1[j];
//			arg1[j] = temp;
//		}
//		j++; 
//	}
//	int temp = arg1[i+1];
//	arg1[i+1] = arg1[end];
//	arg1[end] = temp;
//	return i + 1;
//}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int> vec{ 1,2,3,2,4,2,5,2,3 };
	cout<<Sol.MoreThanHalfNum_Solution(vec);


	return 0;
}







