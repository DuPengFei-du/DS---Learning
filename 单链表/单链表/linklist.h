#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//�ȶ�����Ľṹ��
typedef struct Node
{
	int val;
	struct Node* next;
}Node;

//Ȼ���ڶ���һ������Ľṹ��
//���򲻴�ͷ��ѭ��������������ľ��ǵ�һ����㡣
typedef struct List
{
	Node* head;   //����ĵ�һ�����
}List;


//��ʼ��
void ListInit(List* list)
{
	list->head = NULL;
}

//����
void Destroy(List* list)
{
	//�ͷ�һ����������Ҫ�������е�ÿһ�����
	//��Ҫ�ͷŵ�����������ȥ��������
	//�ͷŵ������еĽ��
	Node* cur = list->head;
	while (cur != NULL)
	{
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	list->head = NULL;
}

//ͷ��
//�����֮ǰ����һ��ȥ���
//֮ǰ��ͷ�壬�����return����Ϊ������򲻴�ͷ��ѭ��������
//�Ѿ���ͷ�����ڽṹ�����ˣ��Ͳ�����return��
void ListPushFront(List* list, int val)
{
	//��װ��һ���������
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = list->head;
	list->head = node;
}

//β��
void PushBack(List* list, int val)
{
	//��װ�����
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	Node* cur = list->head;
	while (cur != NULL)
	{
		cur = cur->next;
	}
	//����Ϊ���һ�����
	//���Խ���β����.
	cur->next = node;
	node->next = NULL;
}

//ͷɾ
void ListPopFront(List* list)
{
	//���Ҫɾ��������Ҫȷ�������Ƿǿյ�
	assert(list->head != NULL);
	Node* second = list->head->next;
	free(list->head);
	list->head = second;
}

//βɾ
void ListPopBack(List* list)
{
	//ȷ�������ǿյ�
	assert(list->head != NULL);
	//����Ҫ���������
	//����ֻ��һ�����Ļ�
	if (list->head->next == NULL)
	{
		free(list->head);
		list->head = NULL;
	}
	else
	{
		Node* cur = list->head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

//�����±�������
//index�϶��ǺϷ����±��ǰ����
void ListInsert(List* list, int index, int val)
{
	//�����룬����ҲҪ�ҵ��±�Ϊindex��Ԫ�ص�ǰ�����
	Node* prev = list->head;
	for (int i = 0; i < index - i; i++)
	{
		prev = prev->next;
	}
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = prev->next;
	prev->next = node;
}

//�󳤶�
int ListLength(List* list)
{
	int count = 0;
	for (Node* cur = list->head; cur != NULL; cur = cur->next)
	{
		count++;
	}
	return count;
}