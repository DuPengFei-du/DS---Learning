#include"List.h"


void ListInit(List* s)
{
	assert(s);
	s->head = NULL;
}

void ListDestroy(List* s)
{
	Node* cur = NULL;
	assert(s);
	cur = s->head;
	while (cur)
	{
		s->head = cur->next;
		free(cur);
		cur = s->head;
	}
	s->head = NULL;
}

void ListPrint(List* s)
{
	Node* cur = NULL;
	assert(s);
	cur = s->head;
	while (cur)
	{
		printf("%d---->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

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
	return pNewNode;
}

void ListPushBack(List* s, int data)
{
	Node* cur = NULL;
	Node* pNewNode = NULL;
	assert(s);
	pNewNode = CreateNode(data);
	cur = s->head;
	if (NULL == s->head)
	{
		s->head = pNewNode;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = pNewNode;
		pNewNode->next = NULL;
	}
}

void ListPushFront(List* s, int data)
{
	Node* pNewNode = NULL;
	assert(s);
	pNewNode = CreateNode(data);
	pNewNode->next = s->head;
	s->head = pNewNode;
}

void ListPopBack(List* s)
{
	Node* cur = NULL;
	assert(s);
	cur = s->head;
	if (NULL == s->head)
		return;
	else if (NULL == s->head->next)
	{
		free(s->head);
		s->head = NULL;
	}
	else
	{
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void ListPopFront(List* s)
{
	Node* cur = NULL;
	assert(s);
	cur = s->head;
	s->head = cur->next;
	free(cur);
	cur = s->head;
}

void ListInsert(Node* pos, int data)
{
	Node* pNewNode = NULL;
	if (pos == NULL)
		return;
	pNewNode = CreateNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}