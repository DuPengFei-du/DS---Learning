#include"DList.h"

Node* CreatrNode(int data)
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
	return  pNewNode;
}

void DLNodeInit(Node** head)
{
	*head = CreatrNode(0);
	(*head)->prev = *head;
	(*head)->next = *head;
}

void DLNodeDestroy(Node** head)
{
	Node* cur = NULL;
	assert(*head);
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

void DLNodePushBack(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head);
	pNewNode = CreatrNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	head->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void DLNodePushFront(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head);
	pNewNode = CreatrNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	head->next = pNewNode;
	pNewNode->next->prev = pNewNode;
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

void DLNodePopBack(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->prev;
	cur->prev->next = head;
	head->prev = cur->prev;
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
	if (pos == NULL)
		return;
	Node* pNewNode = NULL;
	pNewNode = CreatrNode(data);
	pNewNode->next = pos;
	pNewNode->prev = pos->prev;
	pos->prev = pNewNode;
	pNewNode->prev->next = pNewNode;   
}

void DLNodeErase(Node* pos)
{
	if (NULL == pos)
		return;
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
}