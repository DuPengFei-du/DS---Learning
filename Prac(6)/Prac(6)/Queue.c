#include"Queue.h"


void QListInit(QList* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

void QListDestroy(QList* q)
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
	Node* pNewNode= (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;
	return pNewNode;
}

//入队列
void QListPush(QList* q, int data)
{
	assert(q);
	Node* pNewNode = CreateNode(data);
	if (NULL == q->front)
	{
		q->front = q->rear = pNewNode;
	}
	else
	{
		q->rear->next = pNewNode;
		q->rear = pNewNode;
		pNewNode->next = NULL;
	}
}

void QListPop(QList* q)
{
	//出队列同样需要分情况讨论
	assert(q);
	if (NULL == q->front)
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
		cur = q->front;
	}
}

int QListEmpty(QList* q)
{
	assert(q);
	if (NULL == q->front)
		return 1;
	return 0;
}

int QListSize(QList* q)
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