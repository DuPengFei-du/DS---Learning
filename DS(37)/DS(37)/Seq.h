#pragma once

#define Default_Capacity 100

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
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

void SeqListPopBack(SeqList* seq);

void SeqListPopFront(SeqList* seq);

void SeqListInsert(SeqList* seq,int index,int data);

void SeqListPrint(SeqList* seq);
