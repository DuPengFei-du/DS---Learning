#include"List.h"


void SListInit(SList* pl)
{
	assert(pl);
	pl->head = NULL;
}

void SListDestroy(SList* pl)
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
		return NULL ;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;
	return pNewNode;
}

void SListPushBack(SList* pl, int data)
{
	Node* pNewNode = NULL;
	Node* cur = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	if (NULL == pl->head)
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

void SListPushFront(SList* pl, int data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void SListPopBack(SList* pl)
{
	//分情况进行讨论
	Node* cur = NULL;
	assert(pl);
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
		cur = pl->head;
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void SListPopFront(SList* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	pl->head = cur->next;
	free(cur);
	cur = pl->head;
}

void SListInsert(Node* pos, int data)
{
	if (NULL == pos)
		return;
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}

void SListErase(SList* pl, Node* pos)
{
	Node* cur = NULL;
	if (NULL == pos)
		return;
	assert(pl);
	cur = pl->head;
	if (pos == pl->head)
	{
		pl->head = pos->next;
		free(pos);
		return;
	}
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
}

Node *SListFind(SList* pl, int data)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur)
	{
		if (data == cur->data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void SListPrint(SList* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur)
	{
		printf("%d--->",cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}