#include"DList.h"

Node* CreateNode(int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->prev = NULL;
	pNewNode->next = NULL;
	pNewNode->data = data;
	return pNewNode;
}

void DListInit(Node** phead)
{
	//带头节点的双向循环链表，需要先创建一个头结点出来
	//所以需要传递二级指针
	*phead = CreateNode(0);
	(*phead)->next = *phead;
	(*phead)->prev = *phead;
}

void DListPushBack(Node* phead, int data)
{
	Node* pNewNode = NULL;
	assert(phead);
	pNewNode = CreateNode(data);
	pNewNode->prev = phead->prev;
	pNewNode->next = phead;
	phead->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void DListPrint(Node* phead)
{
	Node* cur = NULL;
	assert(phead);
	cur = phead->next;
	while (cur != phead)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void DListDestroy(Node** phead)
{
	Node* cur = NULL;
	assert(phead);
	cur = (*phead)->next;
	while (cur != *phead)
	{
		(*phead)->next = cur->next;
		free(cur);
		cur = (*phead)->next;
	}
	(*phead)->next = *phead;
	(*phead)->next = *phead;
	free(*phead);
	*phead = NULL;
}