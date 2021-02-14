#include"Queue.h"


void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

void QueueDestroy(Queue* q)
{
	//队列的销毁操作
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

void QueuePush(Queue* q,int data)
{
	assert(q);
	Node* pNewNode = CreateNode(data);
	if (NULL == q->front)
	{
		q->front = q->rear = pNewNode;
		pNewNode = q->front;
	}
	else
	{
		Node* cur = q->front;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = pNewNode;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	Node* cur = q->front;
	q->front = cur->next;
	free(cur);
	return;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	if (NULL == q->front)
		return 1;
	return 0;
}

int QueueSize(Queue* q)
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