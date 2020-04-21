#pragma once

#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;

typedef int (*PFC)(HPDataType left, HPDataType right);  //给函数指针类型

//PFC是函数指针类型

typedef struct Heap
{
	HPDataType* array;
	int _capacity;
	int _size;   //堆中有效元素的个数
	PFC _pFC;   
}Heap;

int Less(HPDataType left, HPDataType right);

int Greater(HPDataType left, HPDataType right);


void CreatHeap(Heap* hp, HPDataType* array, int size,PFC pFC);

void AdjustUp(HPDataType* array, int size, int child);

void EraseHeap(Heap* hp);   //删除堆顶元素

int SizeHeap(Heap* hp);

int EmptyHeap(Heap* hp);

void DestroyHeap(Heap* hp);

HPDataType TopHeap(Heap* hp);

void InsertHeap(Heap* hp, HPDataType data);



////////////////////////////////////////////////////

//堆排序
void HeapSort(int* array, int size);