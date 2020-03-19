#include"List.h"

void ListInit(List* s)
{
	assert(s);
	s->head = NULL;   //因为一个结点都没有，那么就吧头置成空
}

Node *CreatNode(int data)  //因为要返回结点，所以返回值为Node*
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

void ListPushBack(List* s, int data)
{
	//尾插的思路：
	//遍历找到最后一个结点，让最后一个结点的next域变为新的结点
	Node* pNewNode = NULL;
	Node* pCur = NULL;
	assert(s);
	pNewNode = CreatNode(data);
	pCur = s->head;
	if (s->head == NULL)
	{
		s->head = pNewNode;
	}
	else
	{
		while (pCur->next)
		{
			pCur = pCur->next;
		}
		pCur->next = pNewNode;
	}
}

void ListPrint(List* s)
{
	Node* pCur = NULL;
	assert(s);
	pCur = s->head;
	while (pCur)
	{
		printf("%d--->", pCur->data);
		pCur = pCur->next;
	}
	printf("NULL\n");
}