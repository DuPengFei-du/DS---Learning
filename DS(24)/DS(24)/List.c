#include"List.h"

void SListInit(List* list)
{
	assert(list);
	//头节点初始化成空的就可以了
	list->head = NULL;
}

void SListDestroy(List* list)
{
	//如何销毁一个链表
	//需要一个结点一个结点去释放
	Node* pcur = NULL;
	assert(list);
	pcur = list->head;
	while (pcur)
	{
		list->head = pcur->next;
		free(pcur);
		pcur = list->head;
	}
	list->head = NULL;
}

Node *CreateNode(int data)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNode)
	{
		assert(0);
		return NULL;
	}
	pNode->data = data;
	pNode->next = NULL;
	return pNode;
}

void SListPushBack(List* list, int data)
{
	Node* pcur = NULL;
	assert(list);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pcur = list->head;
	if (list->head == NULL)
	{
		list->head = pNewNode;
	}
	else
	{
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		//pcur已经是最后一个结点了
		pcur->next = pNewNode;
		pNewNode->next = NULL;
	}
}

void SListPrint(List* list)
{
	Node* pcur = NULL;
	assert(list);
	pcur = list->head;
	while (pcur)
	{
		printf("%d--->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}