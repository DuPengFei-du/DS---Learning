#include"Queue.h"


void QListNodeInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

void QListNodeDestroy(Queue* q)
{
	assert(q);
	Node* cur = q->front;
	while (cur)
	{
		q->front = cur->next;
		free(cur);
		cur = q->front;
	}
	q->front = q->rear = NULL;
}

Node* CreateNode(int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->next= NULL;
	return pNewNode;
}

void QListNodePush(Queue* q, int data)
{
	assert(q);
	Node* pNewNode = CreateNode(data);
	if (q->front == NULL)
		q->front = q->rear = pNewNode;
	else
	{
		q->rear->next = pNewNode;
		q->rear = pNewNode;
	}
}

void QListNodePop(Queue* q)
{
	assert(q);
	Node* cur = q->front;
	if (NULL == q->front)
		return;
	else if (q->front == q->rear)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		q->front = cur->next;
		free(cur);
	}
}

int QListNodeEmpty(Queue* q)
{
	assert(q);
	if (q->front == NULL)
		return 1;
	return 0;
}

int QListNodeSize(Queue* q)
{
	assert(q);
	int count = 0;
	Node* cur = q->front;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}