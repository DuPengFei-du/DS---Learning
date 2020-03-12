#pragma once

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//静态顺序表
//typedef struct SeqList
//{
//	int arr[100];
//	int size;
//	int capacity
//}SeqList;


//动态顺序表
#define Dafault_Capacity 100

typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;


//初始化
void SeqListInit(SeqList* seq);

//销毁
void SeqListDestroy(SeqList* seq);

//尾插
void SeqListPushBack(SeqList* seq, int val);

//打印
void SeqListPrint(SeqList* seq);

//头插
void SeqListPushFront(SeqList* seq, int val);

//头删
void SeqListPopFront(SeqList* seq);

//任意位置的插入
void SeqListInsert(SeqList* seq,int index,int val);

//任意位置的删除
void SeqListErase(SeqList* seq, int index);
