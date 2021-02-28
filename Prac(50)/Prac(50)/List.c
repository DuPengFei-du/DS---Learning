#include"List.h"



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

void NodeInit(Node** head)
{
	*head = CreateNode(0);
	(*head)->prev = (*head);
	(*head)->next = (*head);
}

void NodeDestroy(Node** head)
{
	assert(*head);
	Node* cur = (*head)->next;
	while (cur != *head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->prev = (*head);
	(*head)->next = (*head);
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
	pNewNode->prev = head;
	head->next = pNewNode;
	pNewNode->next->prev = pNewNode;
}

void NodePopBack(Node* head)
{
	assert(head);
	Node* cur = head->prev;
	cur->prev->next = head;
	cur->next->prev = cur->prev;
}

void NodePopFront(Node* head)
{
	assert(head);
	Node* cur = head->next;
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
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