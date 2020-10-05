#include"List.h"


void ListInit(List* pl)
{
	assert(pl);
	pl->head = NULL;
}

void ListDestroy(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur)
	{
		pl->head = cur->next;
		free(cur);
		cur = pl->head;
	}
	pl->head = NULL;
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

void ListPushBack(List* pl, int data)
{
	Node* cur = NULL;
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	if (NULL == pl->head)
		pl->head = pNewNode;
	else
	{
		cur = pl->head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = pNewNode;
		pNewNode->next = NULL;
	}
}

void ListPushFront(List* pl, int data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void ListPrint(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void ListPopFront(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	pl->head = cur->next;
	free(cur);
	cur = pl->head;
}

void ListPopBack(List* pl)
{
	//分情况讨论
	Node* cur = NULL;
	assert(pl);
	if (pl->head == NULL)
		return;
	else if (pl->head->next == NULL)
	{
		free(pl->head);
		pl->head = NULL;
	}
	else
	{
		cur = pl->head;
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void ListInsert(Node* pos, int data)
{
	if (pos == NULL)
		return;
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}

Node* ListFind(List* pl, int data)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}