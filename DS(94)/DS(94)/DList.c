#include"DList.h"

Node* CreateNode(int data)
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

void NodeInit(Node** head)
{
	(*head) = CreateNode(0);
	(*head)->prev = *head;
	(*head)->next = *head;
}

void NodeDestroy(Node** head)
{
	assert(*head);
	Node* cur = NULL;
	cur = (*head)->next;
	while (cur!=(*head))
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->prev = *head;
	(*head)->next = *head;
}

void NodePushBack(Node* head, int data)
{
	assert(head);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	pNewNode->prev->next = pNewNode;
	head->prev = pNewNode;
}

void NodePushFront(Node* head, int data)
{
	assert(head);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	head->next = pNewNode;
	pNewNode->next->prev = pNewNode;
}

void NodePopFront(Node* head)
{
	assert(head);
	Node* cur = NULL;
	cur = head->next;
	head->next = cur->next;
	free(cur);
	cur = head->next;
}

void NodePopBack(Node* head)
{
	assert(head);
	Node* cur = NULL;
	cur = head->prev;
	if (head == head->next)
		return;
	cur->prev->next = head;
	head->prev = cur->prev;
	free(cur);
}

void NodePrint(Node* head)
{
	assert(head);
	Node* cur = NULL;
	cur = head->next;
	while (cur != head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

Node* NodeFind(Node* head, int data)
{
	assert(head);
	Node* cur = NULL;
	cur = head->next;
	while (cur != head)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void NodeErase(Node* pos)
{
	if (pos == NULL)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
}