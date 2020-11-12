#pragma once


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef int HPDataType;

typedef struct Heap
{
	HPDataType* array;
	int capacity;
	int size;
}Heap;



//堆的初始化
void HeapInit(Heap* hp,int capacity);   //同时给出初始的容量

//堆的创建---就是用数组中的元素来创建堆
void HeapCreate(Heap* hp,int *array,int size);

//插入元素
void HeapPush(Heap* hp, HPDataType data);

//删除元素
void HeapPop(Heap* hp);

//获取堆顶元素
int HeapTop(Heap* hp);

//堆是不是为空
int HeapEmpty(Heap* hp);

//堆中元素的个数
int HeapSize(Heap* hp);

//堆的销毁
void HeapDestroy(Heap* hp);



/////////////////////////////////////////////////
void TestHeap();