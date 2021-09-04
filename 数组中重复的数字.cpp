//C:\Users\剑南道刺史\OneDrive\Documents\后台开发\题目源码

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication);
};

bool Solution::duplicate(int numbers[], int length, int* duplication) 
{
	unordered_set<int> Index;
	int Count(0);
	while (Count<length)
	{
		if (Index.find(numbers[Count]) == Index.end())
			Index.insert(numbers[Count]);
		else
		{
			*duplication = numbers[Count];
			return true;
		}
		Count++;
	}
	return false;
}


int main()
{
	Solution Sol;
	int buff[] = { 2,4,2,1,4 };
	int *ptr = new int(1);


	cout << Sol.duplicate(buff, 5, ptr) << " " << *ptr;




	return 0;
}
