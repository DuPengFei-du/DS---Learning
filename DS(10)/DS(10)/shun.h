#pragma once

#include<assert.h>
#include<string.h>
#include<stdio.h>

//静态顺序表的结构
//typedef struct SeqList
//{
//	int array[100];
//	int size = 0;
//	int capacity = 0;
//}SeqList;

//动态顺序表结构
#define Default_Capacity 100
typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;


//可以进行操作了
//初始化操作
void SeqListInit(SeqList* seq);

//销毁操作
void SeqListDestroy(SeqList* seq);

//尾插操作--时间复杂度为O(1)
void SeqListPushBack(SeqList* seq,int val);
