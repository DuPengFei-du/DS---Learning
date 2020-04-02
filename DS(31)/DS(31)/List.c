#include"List.h"

void SListInit(List* pl)
{
	assert(pl);  //看链表是否存在
	//对于链表的初始化，只需要让链表的头为空就可以了
	pl->head = NULL;
}

void SListDestroy(List* pl)
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
	Node* pNewNode = NULL;
	Node* pcur = NULL;
	assert(pl);
	pcur = pl->head;
	pNewNode = CreateNode(data);
	//尾插，分情况讨论，没有结点和有结点
	if (NULL == pl->head)
		pl->head = pNewNode;
	else
	{
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = pNewNode;
	}
}

void SListPopBack(List* pl)
{
	Node* pcur = NULL;
	assert(pl);
	//尾删，分情况讨论
	//没有结点
	//只有一个结点
	//有多个结点
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
		//有多个结点
		while (pcur->next->next)
		{
			pcur = pcur->next;
		}
		free(pcur->next);
		pcur->next = NULL;
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

void SListPopFront(List* pl)
{
	assert(pl);
	if (NULL == pl->head)
		return;
	else
	{
		Node* pDelNode = pl->head;
		pl->head = pDelNode->next;
		free(pDelNode);
	}
}
