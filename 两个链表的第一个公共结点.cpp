#include<iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <queue>


using namespace std;


struct ListNode 
{
int val;
struct ListNode *next;
ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2);
};

ListNode* Solution::FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
{
	int NodeNum1(0), NodeNum2(0);
	ListNode *Node1(pHead1), *Node2(pHead2);
	while (Node1 != nullptr)
	{
		NodeNum1++;
		Node1 = Node1->next;
	}
	while (Node2 != nullptr)
	{
		NodeNum2++;
		Node2 = Node2->next;
	}

	if (NodeNum1 > NodeNum2)
		while (NodeNum1 > NodeNum2)
		{
			pHead1 = pHead1->next;
			NodeNum1--;
		}
	else if(NodeNum1 < NodeNum2)
		while (NodeNum1 < NodeNum2)
		{
			pHead2 = pHead2->next;
			NodeNum2--;
		}
	while (pHead1 != pHead2)
	{
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}
	return pHead1;
}

int main(int argc, char *argv[])
{
	Solution Sol;
	ListNode* List1 = new ListNode(1), *List2=new ListNode(4);
	List1->next = new ListNode(2);
	List1->next ->next= new ListNode(3);
	List1->next->next->next = new ListNode(6);
	List1->next->next->next ->next= new ListNode(7);
	List2->next= new ListNode(5);
	List2->next->next = List1->next->next->next;
	List2->next->next->next = List1->next->next->next->next;
	ListNode* List3=Sol.FindFirstCommonNode(List1, List2);


	return 0;
}



