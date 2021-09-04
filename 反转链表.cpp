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
class Solution {
public:
	ListNode * ReverseList(ListNode* pHead);
};

ListNode * Solution::ReverseList(ListNode* pHead) 
{
	ListNode *NewHead(nullptr);
	ListNode *Node(pHead);
	ListNode *Prev(nullptr);
	

	while (Node!= nullptr)
	{
		ListNode *Next(Node->next);
		if (Next == nullptr)
			NewHead = Node;
		Node->next = Prev;
		Prev = Node;
		Node = Next;
	}
	return NewHead;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	vector<int> vec{ 1,2,3,4,5,6,7 };

	return 0;
}