/*
删除链表中等于给定值 val 的所有节点。


示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

*/


/*
/**
 * Definition for singly-linked list.
 * struct ListNode 
 {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//typedef struct ListNode Node;
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	//先给定一个空链表
//	Node* resulthead = NULL;
//	Node* cur = head;
//	Node* last = NULL;//记录resulthead代表链表的最后一个节点
//	while (cur != NULL)
//	{
//		Node* next = cur->next;
//		if (cur->val != val)
//		{
//			if (resulthead == NULL)
//			{
//				cur->next = resulthead;
//				resulthead = cur;
//			}
//			else
//			{
//				cur->next = NULL;
//				last->next = cur;
//			}
//			last = cur;
//		}
//		cur = next;
//	}
//	return resulthead;
//}
//*/