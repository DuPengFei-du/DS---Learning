#pragma once 



#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


#define Default_Capacity 100

typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;


void SeqListInit(SeqList* s);

void SeqListDestroy(SeqList* s);

void SeqListPushBack(SeqList* s,int data);

void SeqListPushFront(SeqList* s, int data);

void SeqListPopBack(SeqList* s);

void SeqListPopFront(SeqList* s);

void SeqListPrint(SeqList* s);

void SeqListInsert(SeqList* s,int index,int data);

void SeqListErase(SeqList* s, int index);

int SeqListFind(SeqList* s,int data);
