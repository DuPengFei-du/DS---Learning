#include"queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;  //队头和队尾相同，表示没有元素
}

QNode* BuyQNode(QDataType data)
{
	//先申请一个结点
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void QueuePush(Queue* q, QDataType data)
{
	QNode* pNewNode = NULL;
	//相当于是链表的尾插
	assert(q);
	//队尾指针可能为空，所以需要分情况讨论
	//空队列
	pNewNode = BuyQNode(data);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = pNewNode;
	}
	else
	{
		q->_rear->_pNext = pNewNode;
		q->_rear = pNewNode;
	}
}

void QueuPop(Queue* q)
{
	assert(q);
	if (NULL == q->_front)
		return;
	else if (q->_front == q->_rear)   //表明队列中只有一个元素
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
	}
	else    //多个元素
	{
		QNode* pDel = q->_front;
		q->_front = pDel->_pNext;
		free(pDel);
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

int QueueSize(Queue* q)
{
	QNode* pCur = NULL;
	assert(q);
	int count = 0;
	pCur = q->_front;
	while (pCur)
	{
		pCur = pCur->_pNext;
		count++;
	}
	return count;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_front;
}

void QueueDestroy(Queue* q)
{
	QNode* pCur = NULL;
	assert(q);
	pCur = q->_front;
	while (pCur)
	{
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = q->_front;
	}
	q->_front = q->_rear = NULL;
}