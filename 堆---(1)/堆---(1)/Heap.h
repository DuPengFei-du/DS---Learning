#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef int HDataType;


int Less(HDataType left, HDataType right);
int Greater(HDataType left, HDataType right);

//CmpΪ����ָ�����
//�������ָ���������ָ����������HDataType�����Լ�һ��int���ͷ���ֵ�����к���
int (*Cmp)(HDataType left, HDataType right);


//��˳���Ľṹ��ʵ��һ��һ����
typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
	//Ϊ�˷���Ƚϵķ�ʽ�����Ǹ��ѽṹ�ж��һ������

}Heap;


void HeapInit(Heap* hp,int init);   //��ʼ��

void HeapCreate(Heap* hp, int* array, int size);

void HeapPush(Heap* hp, HDataType data);

void HeapPop(Heap* hp);

HDataType HeapTop(Heap* hp);  //��ȡ�Ѷ�Ԫ��

int HeapEmpty(Heap* hp); 

int HeapSize(Heap* hp);  

void HeapDestroy(Heap* hp);   //����

void TestHeap();

