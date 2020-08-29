#include"Queue.h"


void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

//销毁
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

//入队
void QueuePush(Queue* q, int data)
{
	//入队的时候分情况讨论
	assert(q);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	if (NULL == q->front)
	{
		q->front = q->rear = pNewNode;
	}
	else
	{
		q->rear->next = pNewNode;
		q->rear = pNewNode;
	}
}

//出队
void QueuPop(Queue* q)
{
	//出队的时候也需要分情况讨论
	assert(q);
	if (q->front == NULL)
		return;
	else if (q->front->next == NULL)
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

//元素个数
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

//是否为空
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->front == NULL)
		return 1;
	return 0;
}