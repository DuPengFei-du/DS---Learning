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
	int _capacity;
}Heap;


void HeapCreate(Heap* hp, HPDataType arr[],int size);

void HeapPush(Heap* hp, HPDataType data);

void HeapPop(Heap* hp);

//获取堆顶元素
HPDataType HeapTop(Heap* hp);

//获取堆中元素的个数
int HeapSize(Heap* hp);

int HeapEmpty(Heap* hp);

void HeapDestroy(Heap* hp);

void TestFunc();

//堆排序
void HeapSort(int array[], int size);

//堆排序中的调整
void HeapAdjust(int array[], int size, int parent);