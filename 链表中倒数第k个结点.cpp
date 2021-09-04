
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


struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution 
{
public:
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k);
};

ListNode * Solution::FindKthToTail(ListNode* pListHead, unsigned int k)
{
	ListNode* Front(pListHead),*Back(pListHead);
	if (k == 0||pListHead==NULL)//防止k=0和头指针为空
		return NULL;

	for (unsigned int i(0); i < k - 1; i++)
	{
		if (Front->next == NULL)//防止链表长度小于k
			return NULL;
		else
			Front = Front->next;
	}

	while (Front->next != NULL)
	{
		Back = Back->next;
		Front = Front->next;
	}
	return Back;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int> vec{ 1,2,3,4,5,6,7 };

	return 0;
}