#include"List.h"

void SListInit(List* pl)
{
	assert(pl);
	pl->head = NULL;
}

void SListDestroy(List* pl)
{
	Node* cur = pl->head;
	assert(pl);
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

void SListPushBack(List* pl, int data)
{
	//尾插需要分情况讨论
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
	//分情况进行讨论
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

void SListPopFront(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	pl->head = cur->next;
	free(cur);
	cur = pl->head;
}

Node *SListFind(List* pl, int data)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsert(Node* pos, int data)
{
	Node* pNewNode= NULL;
	if (NULL == pos)
		return;
	pNewNode = CreateNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}

void SListErase(List* pl, Node* pos)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
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