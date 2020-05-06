#include"SList.h"

void SListInit(SList* pl)
{
	assert(pl);
	pl->head = NULL;   //让头节点为空，就算是初始化完成了
}

Node *CreateNode(int data)
{
	Node* pNewnode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewnode)
	{
		assert(0);
		return NULL;
	}
	pNewnode->data = data;
	pNewnode->next = NULL;
	return pNewnode;
}

void SListPushBack(SList* pl, int data)
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

void SListpPrint(SList* pl)
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
}

void SListPopBack(SList* pl)
{
	Node* cur = NULL;
	//尾删需要分情况进行讨论
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

void SListPushFront(SList* pl, int data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void SListPopFront(SList* pl)
{
	Node* cur = NULL;
	assert(pl);
	if (NULL == pl->head)
		return;
	cur = pl->head;
	pl->head = cur->next;
	free(cur);
}