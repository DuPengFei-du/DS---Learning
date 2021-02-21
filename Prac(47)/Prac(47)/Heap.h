#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>



typedef int HPDataType;

//定义一个函数指针类型
typedef int (*CMP)(HPDataType, HPDataType);

typedef struct Heap
{
	HPDataType* array;
	int _size;
	int _capacity;
	CMP Cmp;
}Heap;

//定义出来两种比较的方法
int Less(HPDataType left, HPDataType right);

int Greater(HPDataType left, HPDataType right);

void HeapInit(Heap* hp,int init,CMP cmp);

void HeapCreate(Heap* hp, HPDataType *array,int size, CMP cmp);

void HeapDestroy(Heap* hp);

void HeapPush(Heap* hp,int data);

void HeapPop(Heap* hp);

int HeapEmpty(Heap* hp);

int HeapSize(Heap* hp);

HPDataType HeapTop(Heap* hp);





//////////////////////////////////////
void TestHeap();