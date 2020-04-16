#include"list.h"

void SListInit(List* pl)
{
	assert(pl);
	pl->head = NULL;
}

Node *CreateNode(int data)
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

void SListPushBack(List* pl, int data)
{
	//尾插需要遍历找到最后一个结点
	Node* cur = NULL;
	Node* pNewNode = NULL;
	assert(pl); 
	cur = pl->head;
	pNewNode = CreateNode(data);
	if (NULL == pl->head)
	{
		pl->head = pNewNode;
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

void SListPrint(List* pl)
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

void SListDestroy(List* pl)
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

void SListPushFront(List* pl, int data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void SListPopBack(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur->next->next)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

void SListPopFront(List* pl)
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

Node* SListFind(List* pl, int data)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur)
	{
		if (cur->data == data)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}

void SListErase(List* pl, Node* pos)
{
	Node* pPrePos = NULL;
	assert(pl);
	if (NULL == pl->head || NULL == pos)
		return;
	if (pos == pl->head)
	{
		pl->head = pos->next;
		free(pos);
		return;
	}
	pPrePos = pl->head;
	while (pPrePos->next != pos)
	{
		pPrePos = pPrePos->next;
	}
	pPrePos->next = pos->next;
	free(pos);
}
