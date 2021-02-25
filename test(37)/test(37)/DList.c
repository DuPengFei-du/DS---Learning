#include"DList.h"

Node* CreateNode(int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->prev = NULL;
	pNewNode->next = NULL;
	return pNewNode;
}

void NodeInit(Node** head)
{
	*head = CreateNode(0);
	(*head)->next = (*head);
	(*head)->prev = (*head);
}

void NodeDestroy(Node** head)
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
	(*head)->next = (*head);
	(*head)->prev = (*head);
}

void NodePushBack(Node* head, int data)
{
	assert(head);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	head->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void NodePushFront(Node* head, int data)
{
	assert(head);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->prev = head;
	pNewNode->next = head->next;
	pNewNode->prev->next = pNewNode;
	head->next = pNewNode;
}

void NodePopFront(Node* head)
{
	assert(head);
	Node* cur = NULL;
	cur = head->next;
	head->next = cur->next;
	free(cur);
	cur = head->next;
}

void NodePopBack(Node* head)
{
	assert(head);
	Node* cur = NULL;
	cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = head;
}

void NodePrint(Node* head)
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

Node* NodeFind(Node* head, int data)
{
	assert(head);
	Node* cur = head->next;
	while (cur != head)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void NodeErase(Node* pos)
{
	if (pos == NULL)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
}