/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//如果传入的head是NULL，则直接返回NULL (只有第一次调用传NULL才会走到，否则之前就会走到head->next==NULL)
		//如果传入head满足head->next==NULL，则head是原链表tail，需要返回
		if (head == NULL || head->next == NULL) {
			return head;
		}

		//如果没有满足上面的退出条件，下面这个递归调用会一直递归下去，直到找到tail节点，此处返回的就是tail
		ListNode* tail = reverseList(head->next);

		//此处的head是每次递归调用的传入参数，以[1,2,3,4,5]为例，此处分别是4，3，2，1 注意没有5，因为5满足退出条件在前面返回了
		//head->next指向原链表中当前处理元素的next元素，即head为4时，next为5；head为3时，next为4
		//因此此处让next的next指向正在处理的元素，即让5指向4，让4指向3等等
		head->next->next = head;
		//同时正在处理的元素不能再指向以前的next，暂且将其next置空，等到处理到该元素时上面的操作会让其指向原先前面的元素
		//但是对于原链表第一个元素1，即这儿最后处理的head,因为没有下面的操作了，所以1的next为NULL，符合要求。
		head->next = NULL;
		//每次递归返回都是返回同一个tail，即5，同时5也是反转后链表的第一个元素。这个tail是最后一次递归从退出条件处返回的，然后每次递归返回后都返回给上一层，最后一次head为1的时候，处理结束，返回这个tail
		return tail;
	}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;

struct ListNode* reverseList(struct ListNode* head)
{
	Node* pNewHead = NULL;
	Node* cur = head;
	while (cur)
	{
		head = cur->next;
		cur->next = pNewHead;
		pNewHead = cur;
		cur = head;
	}
	return pNewHead;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head)
{
	//反转链表
	Node* prev = NULL;
	Node* cur = head;
	Node* next = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}