#include"lian.h"

void SListInit(SList* pl)
{
	assert(pl);
	pl->head = NULL;
}

Node* CreataNode(int data)
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

void SListPushBack(SList* pl, int data)
{
	//尾插需要遍历
	Node* pNewNode = NULL;
	Node* cur = NULL;
	assert(pl);
	pNewNode = CreataNode(data);
	cur = pl->head;
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

void SListPrint(SList* pl)
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
	//一个结点一个节点去释放
	Node *cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur)
	{
		pl->head = cur->next;
		free(cur);
		cur = pl->head;
	}
}

void SListPushFront(SList* pl, int data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreataNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void SListPopBack(SList* pl)
{
	//尾删需要找到倒数第二个结点
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

void SListPopFront(SList* pl)
{
	Node* cur = pl->head;
	assert(pl);
	cur = pl->head;
	pl->head = cur->next;
	free(cur);
	cur = pl->head;
}