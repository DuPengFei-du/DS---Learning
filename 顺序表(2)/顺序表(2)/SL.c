#include"SL.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#define DEFAULT_CAPACITY (16)
//��ʼ����ʱ�临�Ӷ�Ϊ0��1��
void SeqListInit(SeqList* seq)
{
	//����ռ�
	//��¼����
	//size =0;
	seq->array = (int*)malloc(sizeof(int) * DEFAULT_CAPACITY);
	seq->capacity = DEFAULT_CAPACITY;
	seq->size = 0;
}
//���ݵ�ʱ�临�Ӷ�Ϊ0��n��
//���ݵĿռ临�Ӷ�һ�㲻����
static void ensurecapacity(SeqList* seq)
{
	if (seq->size < seq->capacity)
	{
		return;
	}
	//ͨ����˵��������¿ռ��СΪ�ɿռ��1.5-2��
	int newCapacity = 2 * seq->capacity;
	int* newArray = (int*)malloc(sizeof(int) * newCapacity);
	for (int i = 0; i < seq->size; i++)
	{
		newArray[i] = seq->array[i];
	}
	free(seq->array);
	seq->array = newArray;
}
//���ٵ�ʱ�临�Ӷ�ҲΪ0��1��
void SeqListDestroy(SeqList* seq)
{
	free(seq->array);
	seq->capacity = 0;
	seq->size = 0;
}
//ͷ���ʱ�临�Ӷ�Ϊ0��n��
void SeqListPushFront(SeqList* seq, int val)
{
	for (int i = seq->size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->size++;
}
//β���ʱ�临�Ӷ�Ϊ0��1��
//����������ݾ���0��n����û�з������ݾ���0��1��
void SeqListPushBack(SeqList* seq, int val)
{
	//�Ȳ����ǷŲ��µ�����
	seq->array[seq->size] = val;
	seq->size++;
}
//�����±�������
//ʱ�临�Ӷ�Ϊ0��n��
void SeqListInsert(SeqList* seq, int index, int val)
{
	//�����ж��±�ĺϷ���
	if (index<0 || index>seq->size)
	{
		printf("�����±�Ƿ�������������\n");
	}
	for (int i = seq->size; i > index; i--)
	{
		seq->array[i] = seq->array[i - 1];
	}
	seq->array[index] = val;
	seq->size++;
}
//��ӡ��ʱ�临�Ӷ�Ϊ0��n��
void SeqListPrint(SeqList* seq)
{
	for (int i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
}
void SeqListPopBack(SeqList* seq)
{
	//�������úϷ��Ե�У��
	if (seq->size <= 0)
	{
		printf("�յ�\n");
		return;
	}
	//assert(seq->size)>0
	seq->size--;
}
//ͷɾ
void SeqListPopFront(SeqList* seq)
{
	for (int i = 0; i <= seq->size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
//�����±�ɾ��
void SeqListErase(SeqList* seq, int index)
{
	assert(seq->size > 0);
	for (int i = index; i < seq->size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
int SeqListFind(SeqList* seq, int val)
{
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] == val)
		{
			return i;
		}
	}
	return -1;
}
void SeqListRemove(SeqList* seq, int val)
{
	int index = SeqListFind(seq, val);
	if (index != -1)
	{
		SeqListErase(seq, index);
	}
}
//ʱ�临�ӶȺͿռ临�Ӷȶ���0��n��
void SeqListRemoveAll(SeqList* seq, int val)
{
	//����ʹ�ö���Ŀռ䣬Ҫ��ʱ���Ͽ��
	int* extra = (int*)malloc(sizeof(int) * seq->size);
	int j = 0;
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] == val)
		{
			extra[j++] = seq->array[i];
		}
	}
	free(seq->array);
	seq->array = extra;
	seq->size = j;
}
//ɾ��֮��˳����л�ʣ���ٸ�����
//��ʣj����