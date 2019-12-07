#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//结点的定义
typedef struct Node
{
	int data;           //数据
	struct Node* next;  //下一个结点的线索
	//next=NULL时，表示没有后续结点了
	//反过来说，最后一个节点的next一定为空·
}Node;


Node *ListPushFront(Node* head, int val); 
void ListPrint(Node* head);//参数是因为我只要找到第一个节点，就可以打印了
Node* ListPushBack(Node* head, int val);
Node* ListPopFront(Node* head);
Node* ListPopBack(Node* head);