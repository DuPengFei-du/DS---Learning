#include"DList.h"

Node* CreateNode(int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->prev = NULL;
	pNewNode->prev = NULL;
	pNewNode->data = data;
	return pNewNode;
}

void DListInit(Node** head)
{
	//先创建一个节点出来
	//让其前后全为自己
	*head = CreateNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;
}

void DListDestroy(Node** head)
{
	//循环去释放结点
	Node* cur = NULL;
	assert(head);
	cur = (*head)->next;
	while (cur!=*head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}
	(*head)->next = *head;
	(*head)->prev = *head;
}

void DListPushBack(Node* head, int data)
{
	Node* pNewNode = NULL;
	assert(head); 
	pNewNode = CreateNode(data);
	pNewNode->prev = head->prev;
	pNewNode->next = head;
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

void DListPopBack(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->prev;
	head->prev = cur->prev;
	cur->prev->next = head;
}

void DListPopFront(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head->next;
	head->next = cur->next;
	cur->next->prev = head;
}

void DListPrint(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head ->next;
	while (cur != head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


Node* Find(Node* head, int data)
{
	Node* cur = NULL;;
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