//不带头节点的单链表

#pragma once      //防止头文件被多次包含

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;   //类型重命名

//给出结点的结构体
typedef struct SListNode
{
	DataType data;
	struct SListNode* next;
}Node;

//给出链表的结构体
//我们只要知道了链表第一个元素的地址，就可以在找到这条完整的链表
typedef struct SList
{
	Node* _pHead;
}SList;


//不带头节点的单链表
//不带头结点的单链表第一个结点中存储的是有效的元素(带头和不带头的区分)

void SListInit(SList* p1);     //初始化

void SListPushBack(SList* p1, DataType data);   //尾插

void SListPopBack(SList* p1);   //尾删

void SListDestroy(SList* p1);

void SListPrint(SList* p1);

void SListPopFront(SList* p1);

void SListPushFront(SList* p1, DataType data);   //尾插

void SListInsertAfter(Node* pos, DataType data);  //在任意位置的插入
 
void SListErase(SList* p1,Node* pos);     //在任意位置的删除

Node* SListFind(SList* p1, DataType data);

int SListSize(SList* p1);    //元素个数

int SListEmpty(SList* p1);   //判断是否为空

Node* SListFront(SList* p1);  //第一个元素

Node* SListBack(SList* p1);     //最后一个元素

void SListRemove(SList* p1, DataType data);    //移除

void SListRemoveAll(SList* p1, DataType data);  //移除所有

