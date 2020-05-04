#include"DList.h"

Node* CreateNode(int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->next = NULL;
	pNewNode->data = data;
	pNewNode->prev = NULL;
	return pNewNode;
}

void DLNodeInit(Node** head)
{
	*head = CreateNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;
}

void DLNodeDestroy(Node** head)
{
	Node* cur = NULL;
	assert(head);
	cur = (*head)->next;
	while (cur != *head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->next = NULL;
	(*head)->prev = NULL;
}

void DLNodePushBack(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head);
	pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	head->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void DLNodePrint(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->next;
	while (cur != head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void DLNodePushFront(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head);
	pNewNode = CreateNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	head->next = pNewNode;
	pNewNode->next->prev = pNewNode;
}

void DLNodePopBack(Node* head)
{
	Node* cur = head;
	assert(head);
	cur = head->prev;
	head->prev = cur->prev;
	cur->prev ->next = head;
}

void DLNodePopFront(Node* head)
{
	Node* cur = head;
	assert(head);
	cur = head->next;
	head->next = cur->next;
	cur->next->prev = head;
}

Node* DLNodeFind(Node* head, int data)
{
	Node* cur = NULL;
	assert(head);
	cur = head->next;
	while (cur != head)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}