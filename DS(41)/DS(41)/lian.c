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
	//β����Ҫ����
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
	//һ�����һ���ڵ�ȥ�ͷ�
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
	//βɾ��Ҫ�ҵ������ڶ������
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