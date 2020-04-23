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

void DLNodeInit(Node** phead)
{
	*phead = CreateNode(0);
	(*phead)->prev = *phead;
	(*phead)->prev = *phead;
	//让头节点的next域和prev域都指向phead本身
}

void DLNodePushBack(Node* phead, int data)
{
	Node* pNewNode = NULL;
	//对于双向链表的插入，先不要破坏原链表的结构
	//先去改变要插入的结点的前驱和后继
	assert(phead);  
	pNewNode = CreateNode(data);
	pNewNode->next = phead;
	pNewNode->prev = phead->prev;
	phead->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void DLNodePirnt(Node* phead)
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

void DLNodeDestroy(Node** phead)
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
	phead = NULL;
}

void DLNodePushFront(Node* phead, int data)
{
	Node* pNewNode = NULL;
	assert(phead);
	pNewNode = CreateNode(data);
	pNewNode->next = phead->next;
	pNewNode->prev = phead;
	phead->next = pNewNode;
	pNewNode->next -> prev = pNewNode;
}

void DLNodePopFront(Node* phead)
{
	Node* cur = NULL;
	assert(phead);
	cur = phead->next;
	if (NULL == phead->next)
		return;
	phead->next = cur->next;
	phead->next->prev = phead;
	free(cur);
}

void DLNodePopBack(Node* phead)
{
	Node* cur = NULL;
	assert(phead);
	if (NULL == phead->next)
		return;
	cur = phead -> prev;
	cur->prev->next = phead;
	phead->prev = cur->prev;
	free(cur);
}

void DLNodeErase(Node* pos)
{
	if (NULL == pos)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
}

void DLNodeInsert(Node* pos, int data)
{
	Node* pNewNode = NULL;
	if (NULL == pos)
		return;
	pNewNode = CreateNode(data);
	pNewNode->next = pos;
	pNewNode->prev = pos->prev;
	pos->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}