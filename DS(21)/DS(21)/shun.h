#pragma once 

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define Default_Capacity 100

typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;

void SeqListInit(SeqList* seq);

void SeqListDestroy(SeqList* seq);

void SeqListPushBack(SeqList* seq, int data);

void SeqListPrint(SeqList* seq);

void SeqListPopBack(SeqList* seq);

void SeqListPushFront(SeqList* seq, int data);

void SeqListPopFront(SeqList* seq);

void SeqListInsert(SeqList* seq,int index,int data);

void SeqListErase(SeqList* seq, int index);

int SeqListFind(SeqList* seq, int data);