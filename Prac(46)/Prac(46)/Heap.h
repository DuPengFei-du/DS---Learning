#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


//���������ֽ׶�����ɵĴ��룬ֻ�������С�ѵĴ���
//�������ϣ��������д�Ĵ���ȿ��Դ�������ֿ��Դ���С�ѵĻ�
//��ô�����Ǿ���Ҫ���뺯��ָ����


//���������ָ������
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

//����Ҫ����һ������ָ�����
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