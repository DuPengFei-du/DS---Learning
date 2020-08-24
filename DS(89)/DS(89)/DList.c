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
	pNewNode->prev = NULL;
	pNewNode->data = data;
	return pNewNode;
}

void DListInit(Node** head)
{
	*head = CreateNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;
}

void DListDestroy(Node** head)
{
	assert(*head);
	Node* cur = NULL;
	cur = (*head)->next;
	while (cur != *head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->prev = *head;
	(*head)->next = *head;
}

void DListPushBack(Node* head, int data)
{
	assert(head);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	pNewNode->prev->next = pNewNode;
	head->prev = pNewNode;
}

void DListPushFront(Node* head, int data)
{
	assert(head);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	pNewNode->prev->next = pNewNode;
	head->next = pNewNode;
}

void DListPopFront(Node* head)
{
	assert(head);
	Node* cur = NULL;
	cur = head->next;
	head->next = cur->next;
	free(cur);
	cur = head->next;
}

void DListPopBack(Node* head)
{
	assert(head);
	Node* cur = NULL;
	cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = head;
}

void DListPrint(Node* head)
{
	assert(head);
	Node* cur = NULL;
	cur = head->next;
	while (cur != head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void DListErase(Node* pos)
{
	if (pos == NULL)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
}

Node* DListFind(Node* head, int data)
{
	assert(head);
	Node* cur = NULL;
	cur = head->next;
	while (cur != head)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}