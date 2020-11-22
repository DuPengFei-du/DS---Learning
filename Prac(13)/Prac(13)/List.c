#include"List.h"


void ListInit(List* pl)
{
	assert(pl);
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

void ListDestroy(List* pl)
{
	assert(pl);
	Node* cur = pl->head;
	while (cur)
	{
		pl->head = cur->next;
		free(cur);
		cur = pl->head;
	}
	pl->head = NULL;
}

void ListPushBack(List* pl, int data)
{
	assert(pl);
	Node* cur = pl->head;
	Node* pNewNode = CreateNode(data);
	if (NULL == pl->head)
	{
		pl->head = pNewNode;
		pNewNode = pl->head;
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

void ListPushFront(List* pl, int data)
{
	assert(pl);
	Node* pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void ListPopBack(List* pl)
{
	assert(pl);
	Node* cur = pl->head;
	if (NULL == pl->head)
	{
		return;
	}
	else if (NULL == pl->head->next)
	{
		free(pl->head);
		pl->head = NULL;
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

void ListPopFront(List* pl)
{
	assert(pl);
	Node* cur = pl->head;
	pl->head = cur->next;
	free(cur);;
	cur = pl->head;
}

void ListPrint(List* pl)
{
	assert(pl);
	Node* cur = pl->head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

Node* ListFind(List* pl, int data)
{
	assert(pl);
	Node* cur = pl->head;
	while (cur)
	{
		if (cur->data == data)
			return cur;
	}
	return NULL;
}