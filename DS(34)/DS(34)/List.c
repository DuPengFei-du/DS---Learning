#include"List.h"


void SListInit(List* pl)
{
	//��������ĳ�ʼ����ֻ��Ҫ��ͷ�ڵ�Ϊ�վͿ�����
	assert(pl);
	pl->head = NULL;
}

void SListSDestroy(List* pl)
{
	Node* pcur = NULL;
	assert(pl);
	pcur = pl->head;
	while (pcur)
	{
		pl->head = pcur->next;
		free(pcur);
		pcur = pl->head;
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
	Node* pcur = NULL;
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = CreateNode(data);
	if (pl->head == NULL)
	{
		pl->head = pNewNode;
	}
	else
	{
		pcur = pl->head;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = pNewNode;
		pNewNode->next = NULL;
	}
}

void SListPrint(List* pl)
{
	Node* pcur = NULL;
	assert(pl);
	pcur = pl->head;
	while (pcur)
	{
		printf("%d--->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
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
	Node* pcur = NULL;
	assert(pl);
	//βɾ��Ҫ�������������
	if (NULL == pl->head)
		return;
	else if (NULL == pl->head->next)
	{
		free(pl->head);
		pl->head = NULL;
	}
	else
	{
		pcur = pl->head;
		while (pcur->next->next)
		{
			pcur = pcur->next;
		}
		free(pcur->next);
		pcur->next = NULL;
	}
}

void SListPopFront(List* pl)
{
	Node* pcur = NULL;
	assert(pl);
	if (NULL == pl->head)
		return;
	pcur = pl->head;
	pl->head = pcur->next;
	free(pcur);
}