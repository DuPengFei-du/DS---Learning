#pragma once

#include<stdio.h>
#include<stdlib.h>

// 1. ���

typedef struct DNode {
	int val;
	struct DNode* prev;   //Ϊ����ǰ�����
	struct DNode* next;   //Ϊ���ĺ�̽��
}	DNode;

// 2. ����

typedef struct DList {
	DNode* head;	// ͷ��㣨û����Чֵ��
}	DList;

// ��ʼ��
void DListInit(DList* list) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->val = 0;		// ��������ͷ���� val ���������е���Ч������
	node->next = node;
	node->prev = node;

	list->head = node;
}

//ͷ��
void DListPushFront(DList* list, int val) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->val = val;
	//�����ﻹҪ����ǰ��ָ��ı仯��һ��ʼ�����ǿ����ˡ�
	node->prev = list->head;
	node->next = list->head->next;
	list->head->next->prev = node;
	list->head->next = node;
}

//β��
void DListPushBack(DList* list, int val)
{
	//����Ҫ��һ��������
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node ->val = val;
	//β��Ͳ���Ҫ�ٱ����ˡ���Ϊhead->prev ����ԭ����������һ�����
	node->prev = list->head->prev;
	node->next = list->head;
	list->head->prev->next = node;
	list->head->prev = node;
}

void DListInsertAfterPos(DNode* pos, int val)
{
	//��λ��Ϊpos�Ľ��������һ��ֵ
	//���Ȼ���һ�����ȴ����һ���ڵ���
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->val = val;
	node->prev = pos;
	node->next = pos->next;
	pos->next->prev = node;
	pos->next = node;
}

void DListInsertBeforePos(DNode* pos, int val)
{
	DListInsertAfterPos(pos->prev,val);
}

void DListPushFront(DList* list, int val) {
	DListInsertAfterPos(list->head, val);
}

void DListPushBack(DList* list, int val) {
	DListInsertAfterPos(list->head->prev, val);
}