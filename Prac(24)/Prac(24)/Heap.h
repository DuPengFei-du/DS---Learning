#pragma once 


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef int HPDataType;


typedef struct Heap
{
	HPDataType* array;
	int size;
	int capacity;
}Heap;


void HeapInit(Heap* hp, int init);

void HeapDestory(Heap* hp);

void HeapCreate(Heap* hp, HPDataType *array,int size);

HPDataType HeapTop(Heap* hp);

int HeapSize(Heap* hp);

int HeapEmpty(Heap* hp);

void HeapPop(Heap* hp);

void HeapPush(Heap* hp,int data);

void TestHeap();