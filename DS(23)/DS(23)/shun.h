#pragma once   //防止头文件被重复包含


//静态顺序表
//typedef struct SeqList
//{
//	int array[100];
//	int _size;
//	int _capacity;
//}SeqList;

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define Default_Capacity 100


//动态顺序表
typedef struct SeqList
{
	int* array;
	int _capacity;
	int _size;
}SeqList;

void SeqListInit(SeqList* seq);

void SeqListDestroy(SeqList* seq);

void SeqListPushBack(SeqList* seq, int data);

void SeqListPrint(SeqList* seq);

void SeqListPopBack(SeqList* seq);
