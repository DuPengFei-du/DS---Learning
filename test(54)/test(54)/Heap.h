#pragma once 


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


typedef int HPDataType;


typedef struct Heap
{
	HPDataType* array;
	int _size;
	int capacity;
}Heap;


void HeapInit(Heap* hp, int init);

void HeapDestroy(Heap* hp);

void HeapCreate(Heap* hp,int *array,int size);

HPDataType HeapTop(Heap* hp);

void HeapPop(Heap* hp);

int HeapEmpty(Heap* hp);

int HeapSize(Heap* hp);

void TestHeap();