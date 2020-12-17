#include"Queue.h"


//初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

//销毁
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = NULL;
	while (cur)
	{
		q->front = cur->next;
		free(cur);
		cur = q->front;
	}
	q->front = q->rear = NULL;
}

QNode* CreateNode(int data)
{
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));
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
	assert(q);
	QNode* pNewNode = NULL;
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
	//出队列也需要分情况进行讨论
	assert(q);
	if (NULL == q->front)
	{
		return;
	}
	else if (NULL == q->front->next)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		QNode* cur = q->front;
		q->front = cur->next;
		free(cur);
	}
}

//元素个数
int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QNode* cur = NULL;
	cur = q->front;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

//是否为空
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->front ==  NULL)
		return 1;
	return 0;
}