#include"DList.h"

DLNode* CreateNode(int data)
{
	DLNode* pNewNode = (DLNode*)malloc(sizeof(DLNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->prev = NULL;
	pNewNode->next = NULL;
	return pNewNode;
}

void DLNodeInit(DLNode** head)
{
	*head = CreateNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;
}

void DLNodeDestroy(DLNode** head)
{
	DLNode* cur = NULL;
	assert(head);
	cur = (*head)->next;
	while (cur!=*head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->prev = *head;
	(*head)->next = *head;
}

void DLNodePushBack(DLNode* head, int data)
{
	DLNode* pNewNode = NULL;
	assert(head);
	pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	head->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void DLNodePushFront(DLNode* head, int data)
{
	DLNode* pNewNode = NULL;
	assert(head);
	pNewNode = CreateNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	head->next = pNewNode;
	pNewNode->next->prev = pNewNode;
}

void DLNodePopBack(DLNode* head)
{
	DLNode* cur = NULL;
	assert(head);
	cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = head;
}

void DLNodePopFront(DLNode* head)
{
	DLNode* cur = NULL;
	assert(head);
	cur = head->next;
	head->next = cur->next;
	cur->next->prev = head;
}

void DLNodePrint(DLNode* head)
{
	DLNode* cur = NULL;
	assert(head);
	cur = head->next;
	while (cur != head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void DLNodeInsert(DLNode* pos, int data)
{
	DLNode* pNewNode = NULL;
	if (NULL == pos)
		return;
	pNewNode = CreateNode(data);
	pNewNode->next = pos;
	pNewNode->prev = pos->prev;
	pos->prev = pNewNode;
	pNewNode->prev->next = pNewNode;

}


DLNode* DLNodeFind(DLNode* head, int data)
{
	DLNode* cur = NULL;
	assert(head);
	cur = head->next;
	while (cur!=head)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}