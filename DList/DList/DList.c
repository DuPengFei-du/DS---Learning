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
	//对于双向链表的插入，先不要破坏原链表的结构
	//先去改变要插入的结点的前驱和后继
	assert(pHead);  //pHead中放置的是链表的地址
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
	assert(pHead);  //先断言一下，链表是否存在
	//1.空链表
	if (NULL == pHead->_pNext)
		return;
	//2.链表只有一个结点
	//3.链表中有多个结点
	//2,3情况可以一起处理
	pDelNode = pHead->_pPre;
	pDelNode->_pPre->_pNext = pHead;
	pHead->_pPre = pDelNode->_pPre;
	free(pDelNode);
}

void DListPushFront(DLNode* pHead, DLDataType data)
{
	assert(pHead);
	//1.链表中没有结点
	//2.链表中有结点
	//1,2两种情况可以放在一起，同一块代码完全可以完成功能
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
	//判断是不是空链表
	if (pHead->_pNext == pHead)
		return;  //条件成立，即为空链表
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
		return;   //是空的的话，就无法删除
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
