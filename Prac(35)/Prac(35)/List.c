#include"List.h"


void NodeInit(List* pl)
{
	assert(pl);
	pl->head = NULL;
}

void NodeDestroy(List* pl)
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

void NodePushBack(List* pl, int data)
{
	assert(pl);
	Node* pNewNode = CreateNode(data);
	//β���ʱ����Ҫ���������
	if (NULL == pl->head)
	{
		pl->head = pNewNode;
	}
	else
	{
		Node* cur = pl->head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = pNewNode;
	}
}

void NodePushFront(List* pl, int data)
{
	//ͷ��
	assert(pl);
	Node* pNewNode = CreateNode(data);
	pNewNode->next = pl->head;
	pl->head = pNewNode;
}

void NodePopFront(List* pl)
{
	//ͷɾ
	assert(pl);
	Node* cur = pl->head;
	pl->head = cur->next;
	free(cur);
	cur = pl->head;
}

void NodePopBack(List* pl)
{
	//βɾҲ��Ҫ���������������
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
		Node* cur = pl -> head;
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void NodePrint(List* pl)
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