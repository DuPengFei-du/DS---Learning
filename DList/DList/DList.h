//带头节点的双向循环链表


//为什么要带头
//原因是因为如果不带头的话，那么头插或者头删会比较麻烦
//而且不带头的话需要传递二级指针，带头的话，只需要传递一级指针
//为什么给成双向的？
//(有一个理由是可以逆向打印链表)
//也就是对有些操作会简单一些

#pragma once  // 保证头文件不会被重复包含

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int DLDataType;

//链表的结点结构
typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	DLDataType data;
}DLNode;

//初始化
void DListInit(DLNode** pHead);

//尾插
void DListPushBack(DLNode* pHead, DLDataType data);

//尾删
void DListPopBack(DLNode* pHead);

//头插
void DListPushFront(DLNode* pHead, DLDataType data);

//头删
void DListPopFront(DLNode* pHead);

//销毁
void DListDestroy(DLNode** pHead);

//创建新的结点
DLNode* BuyDLNode(DLDataType data);

//打印函数
void PrintList(DLNode* pHead);

//查找
DLNode* DListFind(DLNode* pHead, DLDataType data);

//任意位置的插入
void DListInsert(DLNode* pos, DLDataType data);

//任意位置的删除
void DListErase(DLNode* pos);

//将链表中有效节点全部清空
void DListClear(DLNode* pos);













