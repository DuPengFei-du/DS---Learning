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


void HeapInit(Heap* hp, int init);   //传一个初始化的容量就可以

void HeapDestroy(Heap* hp);   

void HeapCreate(Heap* hp, int* array, int size);   

void HeapPush(Heap* hp, HPDataType data);

void HeapPop(Heap* hp);

HPDataType HeapTop(Heap* hp);  //获取堆顶元素

int HeapEmpty(Heap* hp);

int HeapSize(Heap* hp);

void TestHeap();