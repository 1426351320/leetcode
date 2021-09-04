class Solution {
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2);
};
ListNode *Solution::Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode *ptr1(pHead1), *ptr2(pHead2),*Head;
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;

	if (pHead1->val > pHead2->val)
	{
		pHead2 ->next= Merge(pHead1, pHead2->next);
		return pHead2;
	}
	else
	{
		pHead1->next = Merge(pHead1->next, pHead2);
		return pHead1;
	}
}