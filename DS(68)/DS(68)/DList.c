#include"DList.h"

DLNode* CreateNode(int data)
{
	DLNode* pNewNode = (DLNode*)malloc(sizeof(DLNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;
	pNewNode->prev = NULL;
	return pNewNode;
}

void DLNodeInit(DLNode** head)
{
	*head = CreateNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;
};

void DLNodeDestroy(DLNode** head)
{
	DLNode* cur = NULL;
	assert(*head);
	cur = (*head)->next;
	while (cur != *head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->next = *head;
	(*head)->prev = *head;
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

void DLNodePopFront(DLNode* head)
{
	DLNode* cur = NULL;
	assert(head);
	cur = head->next;
	head->next = cur->next;
	free(cur);
	cur = head->next;
}

void DLNodePopBack(DLNode* head)
{
	DLNode* cur = NULL;
	assert(head);
	cur = head->prev;
	if (head->next == head)
		return;
	head->prev = cur->prev;
	cur->prev->next = head;
}

DLNode* DLNodeFind(DLNode* head, int data)
{
	DLNode* cur = NULL;
	assert(head);
	cur = head->next;
	while (cur != head)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

DLNode DLNodeInsert(DLNode* pos, int data)
{
	DLNode* pNewNode = NULL;
	if (pos == NULL)
		return;
	pNewNode = CreateNode(data);
	pNewNode->next = pos;
	pNewNode->prev = pos->prev;
	pos->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

DLNode DLNodeErase(DLNode* head, DLNode* pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
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