#pragma once 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define Default_Capacity 100

typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;

void SeqListInit(SeqList* s);

void SeqListDestroy(SeqList* s);

void SeqListPushBack(SeqList* s, int data);

void SeqListPushFront(SeqList* s, int data);

void SeqListPopBack(SeqList* s);

void SeqListPopFront(SeqList* s);

void SeqListInsert(SeqList* s, int index, int data);

void SeqListErase(SeqList* s, int index);

void SeqListPrint(SeqList* s);
