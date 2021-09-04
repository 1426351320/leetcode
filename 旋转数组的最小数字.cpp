
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
	int minNumberInRotateArray(vector<int> rotateArray);
};
int Solution::minNumberInRotateArray(vector<int> rotateArray)
{
	int left(0), right(rotateArray.size()-1),middle((left + right)/2);
	int Min(INT_MAX);

	if (right == 0)
		return 0;
	if (rotateArray[0] < rotateArray[1] && rotateArray[0] < rotateArray.back())//数组未移动
		return rotateArray[0];

	while (right>=left)
	{
		if (rotateArray[left] == rotateArray[middle] && rotateArray[right] == rotateArray[middle])//这种情况就要遍历了
		{
			while (left <= right)
				if (rotateArray[left] < Min)
					Min = rotateArray[left];
			return Min;
		}

		if (left + 1 == right)
		{
			middle = right;
			break;
		}
		if (rotateArray[left] <= rotateArray[middle])
		{
			left = middle;
			middle = (left + right) / 2;
		}
		else if (rotateArray[right] >= rotateArray[middle])
		{
			right = middle;
			middle = (left + right) / 2;
		}
			
	}
	return rotateArray[middle];
}


int main(int argc, char *argv[])
{
	Solution Sol;
	cout<<Sol.minNumberInRotateArray(vector<int>{3, 4, 5, 1, 2});

	return 0;
}