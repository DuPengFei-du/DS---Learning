#include"List.h"


void SListInit(List* pl)
{
	assert(pl);
	//初始化链表，一个结点都没有，只需要将链表的头节点置成空就可以了
	pl->head = NULL;
}

void SListDestroy(List* pl)
{
	//链表遍历的总体思路，就是需要去遍历释放结点
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur)
	{
		pl->head = cur->next;
		free(cur);
		cur = pl->head;
	}
	pl->head = NULL;
}

Node* CreateNode(int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->next = NULL;
	pNewNode->data = data;
	return pNewNode;
}

void SListPushBack(List* pl, int data)
{
	//尾插，需要经过遍历，找到最后一个结点
	Node* cur = NULL;
	Node* pNewNode = NULL;
	assert(pl);
	cur = pl->head;
	pNewNode = CreateNode(data);
	if (pl->head == NULL)
	{
		pl->head = pNewNode;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = pNewNode;
		pNewNode->next = NULL;
	}
}

void SListPrint(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	cur = pl->head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPopBack(List* pl)
{
	Node* cur = NULL;
	assert(pl);
	//分情况讨论
	//链表中没有结点
	//链表中只有一个结点
	//链表中至少有两个结点
	if (NULL == pl->head)
		return;
	else if (NULL == pl->head->next)
	{
		free(pl->head);
		pl->head = NULL;
	}
	else
	{
		//遍历找到倒数第二个结点
		cur = pl->head;
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}