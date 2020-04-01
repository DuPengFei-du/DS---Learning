#include"List.h"

void SListInit(List* pl)
{
	assert(pl);
	pl->head = NULL;
	//让第一个结点为空，就是完成了初始化了
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
	//尾插，就是要找到最后一个结点
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