/*
ɾ�������е��ڸ���ֵ val �����нڵ㡣


ʾ��:
����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5

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
//	//�ȸ���һ��������
//	Node* resulthead = NULL;
//	Node* cur = head;
//	Node* last = NULL;//��¼resulthead������������һ���ڵ�
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