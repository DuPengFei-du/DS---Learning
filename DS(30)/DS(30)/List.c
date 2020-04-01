#include"List.h"

void SListInit(List* pl)
{
	assert(pl);
	pl->head = NULL;
	//�õ�һ�����Ϊ�գ���������˳�ʼ����
}

void SListDestroy(List* pl)
{
	Node* pcur = NULL;
	assert(pl);
	pcur = pl->head;
	while (pcur)
	{
		pl->head = pcur -> next;
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
		asser(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;
	return pNewNode;
}

void SListPushBack(List* pl, int data)
{
	//β�壬����Ҫ�ҵ����һ�����
	Node* pcur = NULL;
	Node* pNewNode= NULL;
	assert(pl);
	pcur = pl->head;
	pNewNode = CreateNode(data);
	while (pcur->next)
	{
		pcur = pcur->next;
	}
	pcur->next = pNewNode;
	pNewNode->next = NULL;
}