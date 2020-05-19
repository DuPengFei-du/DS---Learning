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

//��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* hp);

//��ȡ����Ԫ�صĸ���
int HeapSize(Heap* hp);

int HeapEmpty(Heap* hp);

void HeapDestroy(Heap* hp);

void TestFunc();

//������
void HeapSort(int array[], int size);

//�������еĵ���
void HeapAdjust(int array[], int size, int parent);