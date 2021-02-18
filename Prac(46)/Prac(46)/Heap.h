#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


//但是我们现阶段所完成的代码，只是能完成小堆的创建
//如果我们希望我们所写的代码既可以创建大堆又可以创建小堆的话
//那么，我们就需要引入函数指针了


//定义出函数指针类型
typedef int (*CMP)(HPDataType, HPDataType);

typedef int HPDataType;


typedef struct Heap
{
	HPDataType* array;
	int _size;
	int _capacity;
	CMP Cmp;
}Heap;


int Less(HPDataType left, HPDataType right);

int Greater(HPDataType left, HPDataType right);

//还需要定义一个函数指针变量
int (*Cmp)(HPDataType left, HPDataType right);

void HeapInit(Heap* hp, int init,CMP Cmp);

void HeapDestroy(Heap* hp);

void HeapPop(Heap* hp);

void HeapPush(Heap* hp,int data);

int HeapSize(Heap* hp);

int HeapEmpty(Heap* hp);

HPDataType HeapTop(Heap* hp);

void HeapCreate(Heap* hp,int *array,int size, CMP Cmp);





/////////////////////////////////////////////////////
void TestHeap();