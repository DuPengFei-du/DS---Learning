#pragma once


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef int HPDataType;


typedef struct Heap
{
	HPDataType* array;
	int size;
	int capacity;
}Heap;


void HeapInit(Heap* hp, int init);  //��������һ���ն�

void HeapCreate(Heap* hp, int* array, int size);

HPDataType HeapTop(Heap* hp);

int HeapSize(Heap* hp);

int HeapEmpty(Heap* hp);

//ɾ�����е�Ԫ��
void HeapPop(Heap* hp); 

void HeapDestroy(Heap* hp);  



////////////////////////////////////////
void TestHeap();