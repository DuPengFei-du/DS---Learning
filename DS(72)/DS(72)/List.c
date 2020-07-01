#include"List.h"


void ListInit(List* pl)
{
	assert(pl);
	pl->head = NULL;     //��ɳ�ʼ��
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

void ListPopBack(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	if (NULL == pl->head)
		return;
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

void ListPopFront(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	pl->head = cur->next;
	free(cur);
	cur = pl -> head;
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

void ListInsert(Node* pos, int data)
{
	if (NULL == pos)
		return;
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}

void ListErase(List* pl, Node* pos)
{
	assert(pl);
	Node* cur = NULL;
	cur = pl->head;
	if (pos == pl->head)
	{
		pl->head = pos->next;
		free(pos);
		return;
	}
	while (cur->next != pos)
	{
		pos - pos->next;
	}
	cur->next = pos->next;
	free(pos);
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