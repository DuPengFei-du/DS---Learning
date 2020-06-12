#include"Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->rear = q->front = NULL;
}

void QueueDestroy(Queue* q)
{
	Node* cur = NULL;
	assert(q);
	cur = q->front;
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
	pNewNode->next = NULL;
	return pNewNode;
}

void QueuePush(Queue* q, int data)
{
	Node* pNewNode = NULL;
	assert(q);
	pNewNode = CreateNode(data);
	if (NULL == q->front)
		q->front = q->rear = pNewNode;
	else
	{
		q->rear->next = pNewNode;
		q->rear = pNewNode;
	}
}

void QueuePop(Queue* q)
{
	//分情况讨论
	Node* cur = NULL;
	if (NULL == q->front)
		return;
	else if (q->front == q->rear)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		cur = q->front;
		q->front = cur->next;
		free(cur);
		cur = q->front;
	}
}

int QueueSize(Queue* q)
{
	Node* Cur = NULL;
	assert(q);
	int count = 0;
	Cur = q->front;
	while (Cur)
	{
		Cur = Cur->next;
		count++;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->front;
}

int QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}

int QueueBack(Queue* q)
{
	assert(q);
	return q->rear->data;
}