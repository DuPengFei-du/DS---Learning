/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 


示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

*/

/*
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */




//typedef struct ListNode Node;
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//	//先给定一个空的结果链表
//	Node* last = NULL;//记录resulthead的最后一个结点
//	Node* resulthead = NULL;
//	Node* c1 = l1;//遍历l1链表
//	Node* c2 = l2;//遍历l2链表
//	while (c1 != NULL && c2 != NULL)
//	{
//		if (c1->val < c2->val)
//			//将c1尾插到结果链表中
//		{
//			Node* next = c1->next;
//			if (resulthead == NULL)
//				resulthead = c1;
//			else
//			{
//				c1->next = NULL;
//				last->next = c1;
//			}
//			last = c1;
//			c1 = next;//让c1往后走
//		}
//		else   //尾插c2;
//		{
//			Node* next = c2->next;
//			if (resulthead == NULL)
//				resulthead = c2;
//			else
//			{
//				c2->next = NULL;
//				last->next = c2;
//			}
//			last = c2;
//			c2 = next;//让c2往后
//		}
//	}
//	//只是一个链表的循环结束了，另一个链表还没有结束
//	//剩余的结点至少要比结果链表中的值要打，last为结果链表中的
//	//最后一个结点，这时候我们看c1和c2那个还有结点，直接接在
//	//last的后面就可以了。
//	if (c1 != NULL)
//		last->next = c1;
//	else
//		last->next = c2;
//	return resulthead;
//}
