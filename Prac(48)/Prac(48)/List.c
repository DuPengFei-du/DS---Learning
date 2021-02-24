#include"List.h"



void ListInit(List* pl)
{
	//对链表进行初始化的操作
	assert(pl);
	pl->head = NULL;
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
	assert(pl);
	Node* pNewNode = CreateNode(data);
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
	Node* pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void ListPopFront(List* pl)
{
	assert(pl);
	Node* cur = pl -> head;
	pl->head = cur->next;
	free(cur);
	cur = pl->head;
}

void ListPopBack(List* pl)
{
	//尾删，需要分情况进行讨论
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
		Node* cur = pl->head;
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
	Node* cur = pl->head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}