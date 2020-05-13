#include"DList.h"

void SListInit(SList* pl)
{
	assert(pl);
	//初始化的时候，链表中一个结点都没有
	//所以让头节点指向空就可以了
	pl->_pHead = NULL;
}

Node* BuySListNode(SDataType data)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	//判断是否申请空间成功
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
	//用来遍历的结点
	Node* pCur = NULL;
	//先需要构造出来一个结点
	//链表中的结点是从堆上new出来的
	Node* pNewNode = NULL;    //先将新的结点的赋值成空值
	//紧接着，判断链表是否存在，如果存在的话，我们给出结点
	assert(pl);    //保证链表是存在的 
	//给出结点
	pNewNode = BuySListNode(data);
	pCur = pl->_pHead;
	//空链表
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
	//找链表中的倒数第二个结点    链表至少有两个结点
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
		//至少有两个节点
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
	//只能忘这个位置的后面插入
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



//必须保证有结点才可以
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
