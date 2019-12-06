/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/



/*class Solution {
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		struct ListNode* resultHead = NULL;
		struct ListNode* cur = pHead;
		while (cur != NULL)
		{
			struct ListNode* next = cur->next;
			cur->next = resultHead;
			resultHead = cur;
			cur = next;
		}
		return resultHead;
	}
};
*/
