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
	pNewNode->prev = NULL;
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
	while (cur!=*head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->prev = NULL;
	(*head)->next = NULL;
}

void NodePushBack(Node* head, int data)
{
	assert(head);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->prev = head->prev;
	pNewNode->next = head;
	head->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void NodePushFront(Node* head, int data)
{
	assert(head);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	pNewNode->next->prev = pNewNode;
	head->next = pNewNode;
}

void NodePopBack(Node* head)
{
	assert(head);
	Node* cur = NULL;
	cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = head;
}

void NodePopFront(Node* head)
{
	assert(head);
	Node* cur = NULL;
	cur = head->next;
	head->next = cur->next;
	head = cur->next->prev;
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
		printf("·¢Éú´íÎó!\n");
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
}

Node* NodeFind(Node* head, int data)
{
	assert(head);
	Node* cur = head;
	while (cur != head)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}