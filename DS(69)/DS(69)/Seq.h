#pragma once 

#define Default_Capacity 100

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;


void SeqListInit(SeqList* seq);

void SeqListDestroy(SeqList* seq);

void SeqListPushBack(SeqList* seq,int data);

void SeqListPushFront(SeqList* seq, int data);

void SeqListPopFront(SeqList* seq);

void SeqListPopBack(SeqList* seq);

void SeqListPrint(SeqList* seq);

void SeqListInsert(SeqList* seq,int index,int data);

void SeqListErase(SeqList* seq, int index);









