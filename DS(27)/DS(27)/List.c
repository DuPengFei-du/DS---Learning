#include"List.h"


void SListInit(List* pl)
{
	assert(pl);
	//��ʼ������һ����㶼û�У�ֻ��Ҫ�������ͷ�ڵ��óɿվͿ�����
	pl->head = NULL;
}

void SListDestroy(List* pl)
{
	//�������������˼·��������Ҫȥ�����ͷŽ��
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
	//β�壬��Ҫ�����������ҵ����һ�����
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
	//���������
	//������û�н��
	//������ֻ��һ�����
	//�������������������
	if (NULL == pl->head)
		return;
	else if (NULL == pl->head->next)
	{
		free(pl->head);
		pl->head = NULL;
	}
	else
	{
		//�����ҵ������ڶ������
		cur = pl->head;
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}