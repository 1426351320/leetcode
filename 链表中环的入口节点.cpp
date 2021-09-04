//C:\Users\���ϵ���ʷ\OneDrive\Documents\��̨����\��ĿԴ��

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <unordered_set>
#include<functional>

using namespace std;



struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:
	ListNode * EntryNodeOfLoop(ListNode* pHead);
};

ListNode * Solution::EntryNodeOfLoop(ListNode* pHead)
{
	if (!pHead)
		return nullptr;
	else if (pHead->next == nullptr)
		return nullptr;

	//���Ȳ����Ƿ�Ϊ��
	ListNode* ptr1(pHead), *ptr2(pHead->next->next);
	while (ptr1 != ptr2 && ptr2 != nullptr)
	{
		ptr1= ptr1->next;
		ptr2 = ptr2->next->next;
	}
	if (ptr2 == nullptr)
		return nullptr;

	//���㻷�ĳ���
	int count(0);
	do
	{
		ptr2=ptr2->next;
		count++;
	} while (ptr2 != ptr1);

	//����ָ�����һ�����ĳ���
	ptr1 = pHead;
	ptr2 = pHead;
	while (count--)
		ptr2 = ptr2->next;
	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return ptr2;
}


int main()
{
	Solution Sol;
	vector<int> vec{ 1,4,2,6,3,5,1,3,2,0 };
	ListNode* head = new ListNode(1);
	//head->next= new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	//head->next->next->next->next->next = new ListNode(6);
	//head->next->next->next->next->next->next = head->next->next;
	Sol.EntryNodeOfLoop(head);


	return 0;
}
