//不带头结点的单链表   
//不带头结点的话，那么链表表中的第一个节点一顶存储的是有效元素

#pragma once  //保证头文件不被重复包含


#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
//如果想要对链表进行操作，那么首先需要一个结点的结构体

typedef int SDataType;

typedef struct SListNode
{
	SDataType data;
	struct SListNode* _pNext;
}Node;

//为了操作简单，在把链表的结构给出来
//如果想要找到一个链表，那么只需要知道链表的头节点就可以了
typedef struct SList
{
	Node* _pHead;
}SList;

//初始化
void SListInit(SList* pl);

//尾插
void SListPushBack(SList* pl, SDataType data);

//尾删
void SListPopBack(SList* pl);

//销毁
void SListDestroy(SList* pl);

//打印
void PrintSList(SList* pl);

//测试
void TestList();

//头插
void SListPushFront(SList* pl, SDataType data);

//头删
void SListPopFront(SList* pl);

//任意位置的插入
void SListInsert(Node* pos, SDataType data);

//任意位置的删除
void SListErase(SList* pl, Node* pos);   //需要遍历去找到pos的前一个位置

//查找
Node* SListFind(SList* pl, SDataType data);

//个数
int SListSize(SList* pl);


//返回最后一个结点
Node* SListBack(SList* pl);

