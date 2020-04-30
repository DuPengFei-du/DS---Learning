#include"DList.h"


Node *CreateNode(int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->next = NULL;
	pNewNode->prev = NULL;
	pNewNode->data = data;
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
	assert(head);
	cur = (*head)->next;
	while (cur != *head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->prev = *head;
	(*head)->next = *head;
}

void DLNodePrint(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->next;
	while (cur != head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void DLNodePushBack(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head);
	pNewNode = CreateNode(data);
	pNewNode->prev = head->prev;
	pNewNode->next = head;
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

void DLNodePopBack(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->prev;
	cur->prev->next = head;
	head->prev=cur->prev;
}

void DLNodePopFront(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->next;
	head->next = cur->next;
	cur->next->prev = head;
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

void DLNodeErase(Node* pos)
{
	if (NULL == pos)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}