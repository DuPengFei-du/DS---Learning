#include"DList.h"

void SListInit(SList* pl)
{
	assert(pl);
	//��ʼ����ʱ��������һ����㶼û��
	//������ͷ�ڵ�ָ��վͿ�����
	pl->_pHead = NULL;
}

Node* BuySListNode(SDataType data)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	//�ж��Ƿ�����ռ�ɹ�
	if (NULL == pNode)
	{
		assert(0);
		return NULL;
	}
	pNode->data = data;
	pNode->_pNext = NULL;
	return pNode;
}

void SListPushBack(SList* pl, SDataType data)
{
	//���������Ľ��
	Node* pCur = NULL;
	//����Ҫ�������һ�����
	//�����еĽ���ǴӶ���new������
	Node* pNewNode = NULL;    //�Ƚ��µĽ��ĸ�ֵ�ɿ�ֵ
	//�����ţ��ж������Ƿ���ڣ�������ڵĻ������Ǹ������
	assert(pl);    //��֤�����Ǵ��ڵ� 
	//�������
	pNewNode = BuySListNode(data);
	pCur = pl->_pHead;
	//������
	if (NULL == pl->_pHead)
		pl->_pHead = pNewNode;
	else
	{
		while (pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pNewNode;
		pNewNode->_pNext = NULL;
	}
}

void PrintSList(SList* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	while (pCur)
	{
		printf("%d--->", pCur->data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

void SListDestroy(SList* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	while (pCur)
	{
		pl->_pHead = pCur->_pNext;
		free(pCur);
		pCur = pl->_pHead;
	}
	pl->_pHead = NULL;
}

void SListPopBack(SList* pl)
{
	Node* pCur = NULL;
	//�������еĵ����ڶ������    �����������������
	assert(pl);
	if (NULL == pl->_pHead)
	{
		return;
	}
	else if (NULL == pl->_pHead->_pNext)
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
	}
	else
	{
		//�����������ڵ�
		Node* pTailNode = pl->_pHead;
		while (pTailNode->_pNext->_pNext)
		{
			pTailNode = pTailNode->_pNext;
		}
		free(pTailNode->_pNext);
		pTailNode->_pNext = NULL;
	}
}

void SListPushFront(SList* pl, SDataType data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = BuySListNode(data);
	pNewNode->_pNext = pl->_pHead;
	pl->_pHead = pNewNode;
}

void SListPopFront(SList* pl)
{
	assert(pl);
	if (NULL == pl->_pHead)
		return;
	else
	{
		Node* pDelNode = pl->_pHead;
		pl->_pHead = pDelNode->_pNext;
		free(pDelNode);
	}
}

void SListInsert(Node* pos, SDataType data)
{
	Node* pNewNode = NULL;
	//ֻ�������λ�õĺ������
	if (NULL == pos)
		return;
	pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

void SListErase(SList* pl, Node* pos)
{
	Node* pPrePos = NULL;
	assert(pl);
	if (NULL == pl->_pHead || NULL == pos)
		return;
	if (pos == pl->_pHead)
	{
		pl->_pHead = pos->_pNext;
		free(pos);
		return;
	}
	pPrePos = pl->_pHead;
	while (pPrePos->_pNext != pos)
	{
		pPrePos = pPrePos->_pNext;
	}
	pPrePos->_pNext = pos->_pNext;
	free(pos);
}

Node* SListFind(SList* pl, SDataType data)
{
	Node* pCur = pl->_pHead;
	assert(pl);
	while (pCur)
	{
		if (pCur->data == data)
			return pCur;
		pCur = pCur->_pNext;
	}
	return NULL;
}

int SListSize(SList* pl)
{
	int count = 0;
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}



//���뱣֤�н��ſ���
Node* SListBack(SList* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	return pCur;
}
