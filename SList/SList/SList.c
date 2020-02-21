#include"SList.h"

void SListInit(SList* p1)
{
	//��֤����Ҫ����
	assert(p1 != NULL);
	//��ʼ��������ô����������һ��Ԫ�ض�û��
	//��ô����ͷ�ڵ�ָ��վͿ�����
	p1->_pHead = NULL;   //�����ͷ�ڵ�ָ���
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
	//��ȷ���������
	assert(p1 != NULL);
	//�ȹ������һ�����
	//дһ������Ȼ���������������
	pNewNode = CreateNode(data);
	pcur = p1->_pHead;
	if (p1->_pHead == NULL)      //���û�н��Ļ�
		p1->_pHead = pNewNode;
	else     //�н��
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
	//û�н��
	if (p1->_pHead == NULL)
		return;
	//ֻ��һ�����
	else if (p1->_pHead->next == NULL)
	{
		free(p1);
		p1->_pHead = NULL;
	}
	//�����������ϵĽ��
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
	//ֻ�ܲ��ڵ�ǰλ�õĺ���
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
	if (pos = p1->_pHead)     //pos�ڵ�һ������λ��
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