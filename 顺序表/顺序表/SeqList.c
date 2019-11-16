#include"SeqList.h"
#include<stdio.h>
#include<malloc.h>
#define DEFAULT_CAPACITY (16)
void SeqListInit(SeqList* seq)
{
	//����ռ�
	//��¼����
	//size =0;
	seq->array = (int*)malloc(sizeof(int) * DEFAULT_CAPACITY);
	seq->capacity = DEFAULT_CAPACITY;
	seq->size = 0;
}
void SeqListDestroy(SeqList* seq)
{
	free(seq->array);
	seq->capacity = 0;
	seq->size = 0;
}
void SeqListPushFront(SeqList* seq, int val)
{
	for (int i = seq->size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->size++;
}
void SeqListPushBack(SeqList* seq, int val)
{
	//�Ȳ����ǷŲ��µ�����
	seq->array[seq->size] = val;
	seq->size++;
}
//�����±�������
void SeqListInsert(SeqList* seq, int index, int val)
{
	//�����ж��±�ĺϷ���
	if (index<0 || index>seq->size)
	{
		printf("�����±�Ƿ�������������\n");
	}
	for (int i = seq->size; i>index; i--)
	{
		seq->array[i] = seq->array[i-1];
	}
	seq->array[index] = val;
	seq->size++;
}
void SeqListPrint(SeqList* seq)
{
	for (int i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
}
