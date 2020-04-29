#include"List.h"

void ListInit(SList* pl)
{
	assert(pl);
	pl->head = NULL;
}

void ListDestroy(SList* pl)
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
}

Node *CreateNode(SList* pl)
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

void ListPushBack(SList* pl, int data)
{
	Node* pNewNode = NULL;
	Node* cur = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	if (NULL ==  pl->head)
	{
		pl->head = pNewNode;
	}
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

void ListPrint(SList* pl)
{
	Node* cur = NULL;
	assert(pl);
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void ListPushFront(SList* pl, int data);

void ListPopBack(SList* pl);

void ListPopFront(SList* pl);

void ListInsert(Node* pos, int data);

void ListErase(SList* pl, Node* pos);
