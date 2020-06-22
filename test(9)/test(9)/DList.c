#include"DList.h"

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

void DLNodeInit(Node** head)
{
	*head = CreateNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;
}

void DLNodeDestroy(Node** head)
{
	Node* cur = NULL;
	assert(*head);
	while (cur != *head)
	{
		cur = (*head)->next;
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->next = *head;
	(*head)->prev = *head;
}

void DLNodePushBack(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head);
	pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	head->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void DLNodePushFront(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head);
	pNewNode = CreateNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	head->next = pNewNode;
	pNewNode->next->prev = pNewNode;
}

void DLNodePopFront(Node* head)
{	
	Node* cur = NULL;
	assert(head);
	cur = head->next;
	head->next = cur->next;
	cur->next->prev = head;
	free(cur);
}

void DLNodePopBack(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = head;
	free(cur);
}

void DLNodePrint(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur= head->next;
	while (cur != head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

Node* DLNodeFind(Node* head, int data)
{
	Node* cur = head;
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

void DLNodeErase(Node* pos)
{
	if (NULL == pos)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
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