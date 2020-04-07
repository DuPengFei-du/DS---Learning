#include"DList.h"


DLNode* BuyDLNode(DLDataType data)
{
	DLNode* pNewNode = (DLNode*)malloc(sizeof(DLNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;
	pNewNode->data = data;
	return pNewNode;
}
void DListInit(DLNode** pHead)
{
	*pHead = BuyDLNode(0);
	(*pHead)->_pNext = *pHead;
	(*pHead)->_pPre = *pHead;
}

void DListPushBack(DLNode* pHead, DLDataType data)
{
	DLNode* pNewNode = NULL;
	//����˫������Ĳ��룬�Ȳ�Ҫ�ƻ�ԭ����Ľṹ
	//��ȥ�ı�Ҫ����Ľ���ǰ���ͺ��
	assert(pHead);  //pHead�з��õ�������ĵ�ַ
	pNewNode = BuyDLNode(data);
	pNewNode->_pNext = pHead;
	pNewNode->_pPre = pHead->_pPre;
	pHead->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;
}

void PrintList(DLNode* pHead)
{
	DLNode* pCur = NULL;
	assert(pHead);
	pCur = pHead->_pNext;
	while (pCur != pHead)
	{
		printf("%d ", pCur->data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}


void DListPopBack(DLNode* pHead)
{
	DLNode* pDelNode = NULL;
	assert(pHead);  //�ȶ���һ�£������Ƿ����
	//1.������
	if (NULL == pHead->_pNext)
		return;
	//2.����ֻ��һ�����
	//3.�������ж�����
	//2,3�������һ����
	pDelNode = pHead->_pPre;
	pDelNode->_pPre->_pNext = pHead;
	pHead->_pPre = pDelNode->_pPre;
	free(pDelNode);
}

void DListPushFront(DLNode* pHead, DLDataType data)
{
	assert(pHead);
	//1.������û�н��
	//2.�������н��
	//1,2����������Է���һ��ͬһ�������ȫ������ɹ���
	DLNode* pNewNode = BuyDLNode(data);
	pNewNode->_pNext = pHead->_pNext;
	pNewNode->_pPre = pHead;
	pHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;
}

void DListPopFront(DLNode* pHead)
{
	DLNode* pDelNode = NULL;
	assert(pHead);
	//�ж��ǲ��ǿ�����
	if (pHead->_pNext == pHead)
		return;  //������������Ϊ������
	pDelNode = pHead->_pNext;
	pHead->_pNext = pDelNode->_pNext;
	pDelNode->_pNext->_pPre = pHead;
	free(pDelNode);
}

DLNode* DListFind(DLNode* pHead, DLDataType data)
{
	DLNode* pCur = NULL;
	assert(pHead);
	pCur = pHead->_pNext;
	while (pCur != pHead)
	{
		if (pCur->data == data)
			return pCur;
		pCur = pCur->_pNext;
	}
	return NULL;
}

void DListInsert(DLNode* pos, DLDataType data)
{
	DLNode* pDelNode = NULL;
	if (NULL == pos)
		return;
	DLNode* pNewNode = BuyDLNode(data);
	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	pos->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;
}

void DListErase(DLNode* pos)
{
	if (NULL == pos)
		return;   //�ǿյĵĻ������޷�ɾ��
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	free(pos);
}

void DListDestroy(DLNode** pHead)
{
	DListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}

void DListClear(DLNode* pHead)
{
	DLNode* pCur = NULL;
	assert(pHead);
	pCur = pHead->_pNext;
	while (pCur != pHead)
	{
		pHead->_pNext = pCur->_pNext;
		free(pCur);
		pCur = pHead->_pNext;
	}
	pHead->_pNext = pHead;
	pHead->_pPre = pHead;
}
