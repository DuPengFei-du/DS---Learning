#pragma once

#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;

typedef int (*PFC)(HPDataType left, HPDataType right);  //������ָ������

//PFC�Ǻ���ָ������

typedef struct Heap
{
	HPDataType* array;
	int _capacity;
	int _size;   //������ЧԪ�صĸ���
	PFC _pFC;   
}Heap;

int Less(HPDataType left, HPDataType right);

int Greater(HPDataType left, HPDataType right);


void CreatHeap(Heap* hp, HPDataType* array, int size,PFC pFC);

void AdjustUp(HPDataType* array, int size, int child);

void EraseHeap(Heap* hp);   //ɾ���Ѷ�Ԫ��

int SizeHeap(Heap* hp);

int EmptyHeap(Heap* hp);

void DestroyHeap(Heap* hp);

HPDataType TopHeap(Heap* hp);

void InsertHeap(Heap* hp, HPDataType data);



////////////////////////////////////////////////////

//������
void HeapSort(int* array, int size);