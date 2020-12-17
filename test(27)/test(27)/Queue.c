#include"Queue.h"


//��ʼ��
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

//����
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

//���
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

//����
void QueuPop(Queue* q)
{
	//������Ҳ��Ҫ�������������
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

//Ԫ�ظ���
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

//�Ƿ�Ϊ��
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->front ==  NULL)
		return 1;
	return 0;
}