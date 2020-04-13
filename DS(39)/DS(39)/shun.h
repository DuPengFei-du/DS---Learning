#pragma once 

#define DefaultCapacity 100

#include<assert.h>
#include<stdio.h>
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

void SeqListPrint(SeqList* seq);
