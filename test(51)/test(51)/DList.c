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
	* head = CreateNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;
}

void NodeDestroy(Node** head)
{
	assert(*head);
	Node* cur = (*head)->next;
	while (cur != (*head))
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->next = (*head);
	(*head)->prev = (*head);
}

void NodePushBack(Node* head, int data)
{
	assert(head);
	Node* pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	pNewNode->prev->next = pNewNode;
	head->prev = pNewNode;
}

void NodePushFront(Node* head, int data)
{
	assert(head);
	Node* pNewNode = CreateNode(data);
	pNewNode->prev = head->prev;
	pNewNode->next = head->next;
	pNewNode->next->prev = pNewNode;
	head->next = pNewNode;
}

void NodePopFront(Node* head)
{
	assert(head);
	Node* cur = head->next;
	head->next = cur->next;
	free(cur);
	cur = head->next;
}

void NodePopBack(Node* head)
{
	assert(head);
	Node* cur = head->prev;
	cur->prev->next = head;
	cur->next->prev = cur->prev;
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
		printf("error\n");
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
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