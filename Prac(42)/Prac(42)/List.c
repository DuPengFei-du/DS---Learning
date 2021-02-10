#include"List.h"

Node* CreateNode(int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->next = NULL;
	pNewNode->data = data;
	return pNewNode;
}

void ListInit(Node** head)
{
	*head = CreateNode(0);
	(*head)->prev = (*head);
	(*head)->next = (*head);
}

void ListDestroy(Node** head)
{
	assert(*head);
	Node* cur = *head;
	while (cur != *head)
	{
		(*head) = cur->next;
		free(cur);
		cur = (*head);
	}
	(*head)->prev = (*head);
	(*head)->next = (*head);
}

void ListPushBack(Node* head, int data)
{
	assert(head);
	Node* pNewNode = CreateNode(data);
	pNewNode->next = head;
	pNewNode->prev = head->prev;
	pNewNode->prev->next = pNewNode;
	head->prev = pNewNode;
}

void ListPushFront(Node* head, int data)
{
	//ͷ��
	assert(head);
	Node* pNewNode = CreateNode(data);
	pNewNode->next = head->next;
	pNewNode->prev = head;
	pNewNode->next->prev = pNewNode;
	head->next = pNewNode;
}

void ListPopFront(Node* head)
{
	//ͷɾ
	assert(head);
	Node* cur = head->next;
	head->next = cur->next;
	free(cur);
	cur = head -> next;
}

void ListPopBack(Node* head)
{
	//βɾ
	assert(head);
	Node* cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = cur->next;
}

void ListPrint(Node* head)
{
	assert(head);
	Node* cur = head->next;
	while (cur!=head)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}