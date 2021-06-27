#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;


typedef struct Heap
{
	HPDataType* array;
	int _size;
	int _capacity;
}Heap;


void HeapInit(Heap* hp, int init);

void HeapDestroy(Heap* hp);

void HeapCreate(Heap* hp, HPDataType *array,int size);

void HeapPop(Heap* hp);

void HeapPush(Heap* hp,int data);

HPDataType HeapTop(Heap* hp);

int HeapEmpty(Heap* hp);

int HeapSize(Heap* hp);





////////////////////////////////
void TestHeap();
