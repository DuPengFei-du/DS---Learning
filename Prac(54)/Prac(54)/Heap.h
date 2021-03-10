#pragma once 


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef int HPDataType;



typedef struct Heap
{
	HPDataType* array;
	int _size;
	int _capacity;
}Heap;


void HeapInit(Heap* hp, int init);

void HeapCreate(Heap* hp, HPDataType *array,int size);

void HeapDestroy(Heap* hp);

void HeapPush(Heap* hp,int data);

void HeapPop(Heap* hp);

HPDataType HeapTop(Heap* hp);

int HeapSize(Heap* hp);

int HeapEmpty(Heap* hp);



////////////////////////////
void TestHeap();