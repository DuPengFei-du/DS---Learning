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
}Seq;


void SeqListInit(Seq* s);

void SeqListDestroy(Seq* s);

void SeqListPushBack(Seq* s,int data);

void SeqListPushFront(Seq* s, int data);

void SeqListPopFront(Seq* s);

void SeqListPopBack(Seq* s);

void SeqListPrint(Seq* s);