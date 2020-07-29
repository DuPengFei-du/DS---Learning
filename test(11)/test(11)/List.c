#include"List.h"

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
	pNewNode->next = NULL;
	pNewNode->data = data;
	return pNewNode;
}

void DListPushBack(List* pl, int data)
{
	Node* cur = NULL;
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	if (NULL == pl->head)
		pl->head = pNewNode;
	cur = pl->head;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = pNewNode;
	pNewNode->next = NULL;
}

void DListPushFront(List* pl, int data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
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

void DListPopBack(List* pl)
{
	//分情况讨论
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	if (NULL == pl->head)
		return;
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
	if (pos == NULL)
		return;
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}

void DListErase(List* pl, Node* pos)
{
	//分情况讨论
	Node* cur = NULL;
	cur = pl->head;
	if (pos == NULL)
		return;
	else if (pos == pl->head)
	{
		pl->head = pos->next;
		free(pos);
		return;
	}
	else
	{
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}

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