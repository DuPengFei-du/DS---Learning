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

void HeapCreate(Heap* hp, int *array,int size);

void HeapDestroy(Heap* hp);

void HeapPop(Heap* hp);

void HeapPush(Heap* hp, HPDataType data);

HPDataType HeapTop(Heap* hp);

int HeapSize(Heap* hp);

int HeapEmpty(Heap* hp);



////////////////////////////////////////////
void TestHeap();