#pragma once 



#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef int HPDataType;

typedef struct Heap
{
	HPDataType* array;
	int size;
	int capacity;
}Heap;


void HeapInit(Heap* hp, int init);

void HeapCreate(Heap* hp, HPDataType* array, int size);

void HeapDestroy(Heap* hp);

HPDataType HeapTop(Heap* hp);

int HeapEmpty(Heap* hp);

int HeapSize(Heap* hp);

void HeapPop(Heap* hp);



/////////////////////////////////////////////////////////////////////////
void TestHeap();