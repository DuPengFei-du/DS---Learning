#pragma once   //��֤ͷ�ļ����ᱻ�ظ�����

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

//���ṹ
typedef struct ListNode
{
	int data;
	struct ListNode* next;
}Node;

//����ṹ
typedef struct List
{
	Node* head;
}List;


//��ʼ��
void ListInit(List* s);

//β��
void ListPushBack(List* s, int data);

//��ӡ
void ListPrint(List* s);
