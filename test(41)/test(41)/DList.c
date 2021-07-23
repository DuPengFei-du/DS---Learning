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


void NodeInit(Node** head)
{
	*head = CreateNode(0);
	(*head)->next = (*head);
	(*head)->prev = (*head);
}

void NodeDestroy(Node** head)
{
	assert(head);
	Node* cur = (*head)->next;
	while (cur!=*head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head);
	}
	(*head)->next = *head;
	(*head)->prev = *head;
}

void NodePushBack(Node* head, int data)
{
	assert(head);
	Node* pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	head->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void NodePushFront(Node* head, int data)
{
	assert(head);
	Node* pNewNode = CreateNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head->prev;
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
	head->prev = cur->prev;
	cur->prev->next = head;
}

void NodePrint(Node* head)
{
	assert(head);
	Node* cur = head->next;
	while (cur != head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void NodeErase(Node* pos)
{
	if (pos == NULL)
		return;
	pos->prev = pos->next->prev;
	pos->next = pos->prev->next;
}

Node* NodeFind(Node* head, int data)
{
	assert(head);
	Node* cur = head->next;
	while (cur != head)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}