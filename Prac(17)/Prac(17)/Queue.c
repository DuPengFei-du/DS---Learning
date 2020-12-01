#include"Queue.h"



void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

void QueueDestroy(Queue* q)
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
	pNewNode->next = NULL;
	return pNewNode;
}

void QueuePush(Queue* q, int data)
{
	assert(q);
	Node* pNewNode = CreateNode(data);
	if (q->front == NULL)
	{
		q->front = q->rear = pNewNode;
	}
	else
	{
		q->rear->next = pNewNode;
		q->rear = pNewNode;
	}
}

void QueuePop(Queue* q)
{
	//出队列需要分情况讨论
	assert(q);
	if (q->front == NULL)
		return;
	else if (q->front == q->rear)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		Node* cur = q->front;
		q->front = cur->next;
		free(cur);
	}
}

int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	Node* cur = q->front;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	return 0;
}
