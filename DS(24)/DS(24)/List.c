#include"List.h"

void SListInit(List* list)
{
	assert(list);
	//ͷ�ڵ��ʼ���ɿյľͿ�����
	list->head = NULL;
}

void SListDestroy(List* list)
{
	//�������һ������
	//��Ҫһ�����һ�����ȥ�ͷ�
	Node* pcur = NULL;
	assert(list);
	pcur = list->head;
	while (pcur)
	{
		list->head = pcur->next;
		free(pcur);
		pcur = list->head;
	}
	list->head = NULL;
}

Node *CreateNode(int data)
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

void SListPushBack(List* list, int data)
{
	Node* pcur = NULL;
	assert(list);
	Node* pNewNode = NULL;
	pNewNode = CreateNode(data);
	pcur = list->head;
	if (list->head == NULL)
	{
		list->head = pNewNode;
	}
	else
	{
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		//pcur�Ѿ������һ�������
		pcur->next = pNewNode;
		pNewNode->next = NULL;
	}
}

void SListPrint(List* list)
{
	Node* pcur = NULL;
	assert(list);
	pcur = list->head;
	while (pcur)
	{
		printf("%d--->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}