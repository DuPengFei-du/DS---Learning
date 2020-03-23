#include"SList.h"


void SListInit(List *pl)
{
	//先看这个链表是否存在
	assert(pl);
	//因为要初始化链表，所以一开始链表里面其实是什么都没有的，那么
	pl->head = NULL;
	//让头节点为空，完成链表的初始化
}

void SListDestroy(List* pl)
{
	Node* pCur = NULL;
	//确保链表存在
	assert(pl);
	//如果要去释放链表的话，那么需要一个结点一个结点去释放
	pCur = pl->head;
	while (pCur)
	{
		pl->head = pCur->next;
		free(pCur);
		pCur = pl->head;
		//完成一个结点的释放，然后一直去循环释放结点
	}
	//到这里已经全部释放完毕了，记得让头结点为空
	pl->head = NULL;
}

//需要返回结点，所以返回值为Node*
Node* CreatNode(int data)
{
	//先创建一个结点
	Node* node = (Node*)malloc(sizeof(Node));
	if (NULL == node)
	{
		assert(0);
		return NULL;
	}
	//如果创建成功了
	node->data = data;
	node->next = NULL;
	return node;
}

void SListPushBack(List* pl, int data)
{
	Node *pCur=NULL;
	Node* pNewNode = NULL;
	assert(pl);
	//尾插的总体思路：
	//需要遍历链表，找到最后一个结点，然后再最后一个结点的后面插入一个元素就可以了
	//特殊情况，如果链表一开始什么元素都没有的话，那么直接让插入的结点成为头结点就可以了
	pCur = pl->head;
	pNewNode = CreatNode(data);
	if (pl->head == NULL)
		pl->head = pNewNode;
	else
	{
		while (pCur->next)
		{
			pCur = pCur->next;
		}
		//到这里，已经是最后一个节点了
		pCur->next = pNewNode;
		pNewNode->next = NULL;
	}
}

void SListPrint(List* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->head;
	while (pCur)
	{
		printf("%d--->", pCur->data);
		pCur = pCur->next;
	}
	printf("NULL\n");
}