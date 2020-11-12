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



//�ѵĳ�ʼ��
void HeapInit(Heap* hp,int capacity);   //ͬʱ������ʼ������

//�ѵĴ���---�����������е�Ԫ����������
void HeapCreate(Heap* hp,int *array,int size);

//����Ԫ��
void HeapPush(Heap* hp, HPDataType data);

//ɾ��Ԫ��
void HeapPop(Heap* hp);

//��ȡ�Ѷ�Ԫ��
int HeapTop(Heap* hp);

//���ǲ���Ϊ��
int HeapEmpty(Heap* hp);

//����Ԫ�صĸ���
int HeapSize(Heap* hp);

//�ѵ�����
void HeapDestroy(Heap* hp);



/////////////////////////////////////////////////
void TestHeap();