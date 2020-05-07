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
	pNewNode->data = data;
	pNewNode->next = NULL;
	return pNewNode;
}

void DListPushBack(List* pl, int data)
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

void DListPushFront(List* pl, int data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void DListPopBack(List* pl)
{
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

void DListPopFront(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	if (NULL == pl->head)
		return;
	cur = pl->head;
	pl->head = cur->next;
	free(cur);
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
	Node* pNewNode = NULL;
	//只能忘这个位置的后面插入
	if (NULL == pos)
		return;
	pNewNode = BuySListNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}

void DListErase(List* pl, Node* pos)
{
	Node* cur = NULL;
	assert(pl);
	if (pos == pl->head)
	{
		pl->head = pos = > next;
		free(pos);
	}
	cur = pl->head;
	while (cur->next != pos)
	{
		cur = cur -> next;
	}
	cur->next = pos->next;
	free(pos);
}