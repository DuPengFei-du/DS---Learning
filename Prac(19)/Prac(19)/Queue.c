#include"Queue.h"


void NodeInit(Queue* q)
{
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

void NodePush(Queue* q, int data)
{
	assert(q);
	Node* pNewNode = CreateNode(data);
	if (NULL == q->front)
		q->front = q->rear = pNewNode;
	else
	{
		q->rear->next = pNewNode;
		q->rear = pNewNode;
	}
}

void NodePop(Queue* q)
{
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
	}
}

int NodeEmpty(Queue* q)
{
	assert(q);
	if (q->front == NULL)
		return 1;
	return 0;
}

int NodeSize(Queue* q)
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

void NodeDestroy(Queue* q)
{
	assert(q);
	Node *cur = q->front;
	while (cur)
	{
		q->front = cur->next;
		free(cur);
		cur = q->front;
	}
	q->front = q->rear = NULL;
}