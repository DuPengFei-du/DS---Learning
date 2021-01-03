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
	Node* cur = NULL;
	cur = pl->head;
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
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	if (NULL == pl->head)
	{
		pl->head = pNewNode;
		pNewNode = pl->head;
	}
	else
	{
		Node* cur = pl->head;
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
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void ListPopFront(List* pl)
{
	assert(pl);
	Node* cur = NULL;
	cur = pl->head;
	pl->head = cur->next;
	free(cur);
	cur = pl->head;
}

void ListPopBack(List* pl)
{
	//分情况讨论
	assert(pl);
	Node* cur = pl->head;
	if (pl->head == NULL)
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

void ListPrint(List* pl)
{
	assert(pl);
	Node* cur = NULL;
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
	if (pos == NULL)
		printf("请重新输入!\n");
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}

void ListErase(List* pl, Node* pos);

Node* ListFind(List* pl, int data)
{
	assert(pl);
	Node* cur = pl->head;
	while (cur)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
