#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//���Ķ���
typedef struct Node
{
	int data;           //����
	struct Node* next;  //��һ����������
	//next=NULLʱ����ʾû�к��������
	//������˵�����һ���ڵ��nextһ��Ϊ�ա�
}Node;


Node *ListPushFront(Node* head, int val); 
void ListPrint(Node* head);//��������Ϊ��ֻҪ�ҵ���һ���ڵ㣬�Ϳ��Դ�ӡ��
Node* ListPushBack(Node* head, int val);
Node* ListPopFront(Node* head);
Node* ListPopBack(Node* head);