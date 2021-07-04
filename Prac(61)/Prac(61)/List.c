#include"List.h"

Node* CreateNode(int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;
	pNewNode->prev = NULL;
	return pNewNode;
}

void ListInit(Node** head)
{
	*(head) = CreateNode(0);
	(*head)->prev = (*head);
	(*head)->next = (*head);
}

void ListDestroy(Node** head)
{
	assert(*head);
	Node* cur = (*head)->next;
	while (cur != *head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->prev = (*head);
	(*head)->next = (*head);
}

void ListPushBack(Node* head, int data)
{
	assert(head);
	Node* pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	pNewNode->prev->next = pNewNode;
	head->prev = pNewNode;
}

void ListPushFront(Node* head, int data)
{
	assert(head);
	Node* pNewNode = CreateNode(data);
	pNewNode->prev = head;
	pNewNode->next = head->next;
	pNewNode->next->prev = pNewNode;
	head->next = pNewNode;
}

void ListPopFront(Node* head)
{
	assert(head);
	Node* cur = head->next;
	head->next = cur->next;
	cur->next->prev = head;
}

void ListPopBack(Node* head)
{
	assert(head);
	Node* cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = head;
}

void ListPrint(Node* head)
{
	assert(head);
	Node* cur = head->next;
	while (cur != head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}