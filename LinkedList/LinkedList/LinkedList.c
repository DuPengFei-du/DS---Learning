#include"LinkedList.h"

//时间复杂为(1)
Node *ListPushFront(Node* head,int val)
{
	//val 不在结点中，先装入结点中
	//相当于是创建一个新的结点
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = val;
	//让node的下一个结点指向原来链表的第一个节点
	node->next = head;
	//让node 称为新的第一个结点
	head = node;
	return node;
}
void  ListPrint(Node* head)
{
	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->data);
	}
	printf("NULL\n");
}
//时间复杂度为O(n)
//对空联保尾插，第一个结点的地址也会改变
//所以需要返回新的第一个结点的地址。
Node* ListPushBack(Node* head, int val)
{
	//如果不在结点中，先创建一个结点
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = val;
	node->next = NULL;
	if (head != NULL)
	{
		Node* cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
	}
	else
		head = node;
	return head;
}
Node* ListPopFront(Node* head)
{
	assert(head != NULL);
	Node* next = head->next;
	free(head);
	return next;
}
Node* ListPopBack(Node* head)
{
	assert(head != NULL);
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		Node* cur = head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		//释放cur->next的空间
		//让cur->next=NULL;
		free(cur->next);
		cur->next = NULL;
	}
	return head;
}