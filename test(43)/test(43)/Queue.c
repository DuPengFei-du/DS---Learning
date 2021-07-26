#include"Queue.h"


void QueueInit(Queue* q)
{
	//�Զ��н��г�ʼ���Ĳ���
	assert(q);
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

void QueuePush(Queue* q, int data)
{
	//������в���Ԫ�أ�����Ҫ��������һ�����
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
		pNewNode->next = NULL;
	}
}

void QueuePop(Queue* q)
{
	//���е�ɾ����Ҫ�������������
	assert(q);
	if (NULL == q->front)
		return;
	else if (NULL == q->front->next)
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
		count++;
		cur = cur->next;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->front;
}