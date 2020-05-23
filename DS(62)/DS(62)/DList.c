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
	pNewNode->prev = NULL;
	return pNewNode;
}

void DListInit(Node** head)
{
	*head = CreateNode(0);
	(*head)->next = (*head);
	(*head)->prev = (*head);
}

void DListDestroy(Node** head)
{
	Node* cur = NULL;
	assert(head);
	cur = (*head)->next;
	while (cur!=(*head))
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->next = (*head);
	(*head)->prev = (*head);
}

void DListPushBack(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head);
	pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	head->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void DListPushFront(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head);
	pNewNode = CreateNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	head->next = pNewNode;
	pNewNode->next->prev = pNewNode;
}

void DListPopFront(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->next;
	head->next = cur->next;
	free(cur);
	cur = head->next;
}

void DListPopBack(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = head;
}

void DListPrint(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->next;
	while (cur!=head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void DListInsert(Node* pos, int data)
{
	Node* pNewNode = NULL;
	if (pos == NULL)
		return;
	pNewNode = CreateNode(data);
	pNewNode->next = pos;
	pNewNode->prev = pos->prev;
	pos->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void DListErase(Node* head, Node* pos)
{
	if (NULL == pos)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos;
}