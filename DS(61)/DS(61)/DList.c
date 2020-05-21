#include"DList.h"


void DListInit(List* pl)
{
	assert(pl);
	pl->head = NULL;
}

void DListDestroy(List* pl)
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

void DListPushBack(List* pl, int data)
{
	Node* pNewNode = NULL;
	Node* cur = NULL;
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

void DListPushFront(List* pl, int data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void DListPopBack(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	if (NULL == pl->head)
		return;
	while (cur->next->next)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

void DListPopFront(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	pl->head = cur->next;
	free(cur);
	cur = pl->head;
}

void DListPrint(List* pl)
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

void DListInsert(Node* pos, int data)
{
	Node* pNewNode = NULL;
	if (NULL == pos)
		return;
	pNewNode = CreateNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}

void DListErease(List* pl, Node* pos);

Node* Find(List* pl, int data)
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