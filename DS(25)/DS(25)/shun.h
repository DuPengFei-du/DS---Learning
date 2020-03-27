#pragma once

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Default_Capacity 100

typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;

void SeqListInit(SeqList* seq);

void SeqListDestroy(SeqList* seq);

void SeqListPushBack(SeqList* seq,int data);

void SeqListPrint(SeqList* seq);

void SeqListPopBack(SeqList* seq);

void SeqListPushFront(SeqList* seq, int data);

void SeqListPopFront(SeqList* seq);