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

void SeqListInit(SeqList* seq);  

void SeqListPrint(SeqList* seq);

void SeqListDestroy(SeqList* seq);  

void SeqListPushBack(SeqList* seq, int data);  

void SeqListPopBack(SeqList* seq);   

void SeqListPushFront(SeqList* seq, int data);  //Í·²å

void SeqListPopFront(SeqList* seq);   //Í·É¾

void SeqListInsert(SeqList* seq, int index, int data);

void SeqListErase(SeqList* seq, int index); 
