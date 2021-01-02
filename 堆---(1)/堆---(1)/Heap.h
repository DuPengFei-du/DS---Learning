#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef int HDataType;


int Less(HDataType left, HDataType right);
int Greater(HDataType left, HDataType right);

//Cmp为函数指针变量
//这个函数指针变量可以指向任意两个HDataType参数以及一个int类型返回值的所有函数
int (*Cmp)(HDataType left, HDataType right);


//和顺序表的结构其实是一摸一样的
typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
	//为了方便比较的方式，我们给堆结构中多加一个东西

}Heap;


void HeapInit(Heap* hp,int init);   //初始化

void HeapCreate(Heap* hp, int* array, int size);

void HeapPush(Heap* hp, HDataType data);

void HeapPop(Heap* hp);

HDataType HeapTop(Heap* hp);  //获取堆顶元素

int HeapEmpty(Heap* hp); 

int HeapSize(Heap* hp);  

void HeapDestroy(Heap* hp);   //销毁

void TestHeap();

