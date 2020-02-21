#include"SList.h"

void SListInit(SList* p1)
{
	//保证链表要存在
	assert(p1 != NULL);
	//初始化链表，那么就是链表中一个元素都没有
	//那么就让头节点指向空就可以了
	p1->_pHead = NULL;   //链表的头节点指向空
}

Node* CreateNode(DataType data)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNode)
	{
		assert(0);
		return NULL;
	}
	pNode->data = data;
	pNode->next = NULL;
	return pNode;
}

void SListPushBack(SList* p1, DataType data)
{
	Node* pNewNode = NULL;
	Node* pcur = NULL;
	//先确保链表存在
	assert(p1 != NULL);
	//先构造出来一个结点
	//写一个函数然后区调用这个函数
	pNewNode = CreateNode(data);
	pcur = p1->_pHead;
	if (p1->_pHead == NULL)      //如果没有结点的话
		p1->_pHead = pNewNode;
	else     //有结点
	{
		while ((pcur->next) != NULL)
		{
			pcur = pcur->next;
		}
		pcur->next = pNewNode;
		pNewNode->next = NULL;
	}
}

void SListPrint(SList* p1)
{
	Node* pcur = NULL;
	assert(p1 != NULL);
	pcur = p1->_pHead;
	while (pcur != NULL)
	{
		printf("%d--->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

void SListDestroy(SList* p1)
{
	Node* pcur = NULL;
	assert(p1 != NULL);
	pcur = p1->_pHead;
	while (pcur != NULL)
	{
		p1->_pHead = pcur->next;
		free(pcur);
		pcur = p1->_pHead;
	}
	p1->_pHead = NULL;
}

void SListPopBack(SList* p1)
{
	assert(p1 != NULL);
	//没有结点
	if (p1->_pHead == NULL)
		return;
	//只有一个结点
	else if (p1->_pHead->next == NULL)
	{
		free(p1);
		p1->_pHead = NULL;
	}
	//含有两个以上的结点
	else
	{
		Node* cur = p1->_pHead;
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void SListPushFront(SList* p1, DataType data)
{
	Node* pNewNode = NULL;
	assert(p1 != NULL);
	pNewNode = CreateNode(data);
	pNewNode->next = p1->_pHead;
	p1->_pHead = pNewNode;
}

void SListPopFront(SList* p1)
{
	assert(p1 != NULL);
	if (NULL == p1->_pHead)
		return;
	else
	{
		Node* pDelNode = p1->_pHead;
		p1->_pHead = pDelNode->next;
		free(pDelNode);
	}
}

void SListInsertAfter(Node* pos, DataType data)
{
	Node* pNewNode = NULL;
	//只能插在当前位置的后面
	if (NULL == pos)
		return;
	pNewNode = CreateNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;

}

void SListErase(SList* p1, Node* pos)
{
	Node* cur = NULL;
	assert(p1 != NULL);
	if (p1->_pHead == NULL||pos==NULL)
		return;
	if (pos = p1->_pHead)     //pos在第一个结点的位置
	{
		p1->_pHead = pos->next;
		free(pos);
		return;
	}
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
}

Node* SListFind(SList* p1, DataType data)
{
	Node* cur = p1->_pHead;
	while (cur != NULL)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

int SListSize(SList* p1)
{
	int count = 0;
	Node* cur = NULL;
	assert(p1 != NULL);
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

int SListEmpty(SList* p1)
{
	assert(p1 != NULL);
	return NULL == p1->_pHead;
}

Node* SListFront(SList* p1)
{
	assert(p1 != NULL);
	return p1->_pHead;
}

Node* SListBack(SList* p1)
{
	Node* cur = NULL;
	assert(p1 != NULL);
	cur = p1->_pHead;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	return cur;
}