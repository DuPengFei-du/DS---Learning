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

void DListNodeInit(Node** head)
{
	*head = CreateNode(0);
	(*head)->prev = *head;
	(*head)->next = *head;
}

void DListNodeDestroy(Node** head)
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

void DListNodePushBack(Node* head, int data)
{
	//Î²²å
	Node* pNewNode = NULL;
	assert(head);
	pNewNode=CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	head->prev = pNewNode;
	pNewNode->prev->next = pNewNode;
}

void DListNodePushFront(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head);
	pNewNode = CreateNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	head->next = pNewNode;
	pNewNode->next->prev = pNewNode;

}

void DListNodePopBack(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = cur->next;
}

void DListNodePopFront(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->next;
	head->next = cur->next;
	cur->next->prev = head;
}

void DListNodePrint(Node* head)
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

void DListNodeErase(Node* pos)
{
	if (pos == NULL)
		return;
	pos->next = pos->prev->next;
	pos->prev = pos->next->prev;
}

Node* DListNodeFind(Node* head, int data)
{
	Node* cur = NULL;
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