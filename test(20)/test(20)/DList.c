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

void ListInit(Node** head)
{
	*head = CreateNode(0);
	(*head)->prev = *head;
	(*head)->next = *head;
}

void ListDestroy(Node** head)
{
	Node* cur = NULL;
	assert(*head);
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

void ListPushBack(Node* head, int data)
{
	Node* pNewNode = CreateNode(data);
	assert(head);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	head->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void ListPushFront(Node* head, int data)
{
	Node* pNewNode = CreateNode(data);
	assert(head);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	head->next = pNewNode;
	pNewNode->next->prev = pNewNode;
}

void ListPopFront(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->next;
	head->next = cur->next;
	free(cur);
	cur = head->next;
}

void ListPopBack(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->prev;
	cur->prev->next = head;
	cur->next->prev = cur->prev;
}

void ListPrint(Node* head)
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

void ListErase(Node* pos)
{
	if (pos == NULL)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
}

Node* ListFind(Node* head, int data)
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