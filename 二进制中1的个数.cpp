
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
	int  NumberOf1(int n);
};
/*位移法*/
//int  Solution::NumberOf1(int n)
//{
//	int flag(1);
//	int count(0);
//	while (flag)
//	{
//		if (n & flag)
//			count ++ ;
//		flag = flag << 1;
//	}
//	return count;
//}

/*减1相加法*/
int  Solution::NumberOf1(int n)
{
	int count(0);
	while (n)
	{
		n = (n - 1)&n;
		count++;
	}
	return count;
}


int main(int argc, char *argv[])
{
	Solution Sol;
	int i = 1;
	i =i<<32;

	cout<<hex<<i;

	return 0;
}