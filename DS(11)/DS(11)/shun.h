#pragma once 

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//静态顺序表
//typedef struct SeqList
//{
//	int arr[10];
//	int _size;
//	int _capacity;
//}SeqList;


//动态顺序表
#define Default_Capacity 100


typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;


//初始化操作
void SeqListInit(SeqList* seq);

//销毁操作
void SeqListDestroy(SeqList* seq);

//尾插操作
void SeqListPushBack(SeqList* seq,int val);

//尾删
void SeqListPopBack(SeqList* seq);

//打印
void SeqListPrint(SeqList* seq);

//头插
void SeqListPushFront(SeqList* seq, int val);
