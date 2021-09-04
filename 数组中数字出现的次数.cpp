#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2);
};
void Solution::FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
{
	
	int Xor(0);
	for (int i(0); i < data.size(); i++)
		Xor = Xor ^ data[i];

	int Count(0);
	while (!(Xor & (1 << Count)))
		Count++;
		
	vector<int> Temp1, Temp2;
	for (int i(0); i < data.size(); i++)
	{
		if (data[i] & (1 << Count))
			Temp1.push_back(data[i]);
		else
			Temp2.push_back(data[i]);
	}

	int Result1(0), Result2(0);
	for (int i(0); i < Temp1.size(); i++)
		Result1 = Result1 ^ Temp1[i];

	for (int i(0); i < Temp2.size(); i++)
		Result2 = Result2 ^ Temp2[i];

	*num1 = Result1;
	*num2 = Result2;
}


int main()
{
	Solution Sol;

	int *result1=new int(0), *result2= new int(0);
	Sol.FindNumsAppearOnce(vector<int>{2, 4, 3, 6, 3, 2, 5, 5}, result1, result2);

	cout << *result1 << " " << *result2;


	return 0;
}
