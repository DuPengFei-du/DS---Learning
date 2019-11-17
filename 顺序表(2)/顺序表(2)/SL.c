#include"SL.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#define DEFAULT_CAPACITY (16)
//初始化的时间复杂度为0（1）
void SeqListInit(SeqList* seq)
{
	//申请空间
	//记录容量
	//size =0;
	seq->array = (int*)malloc(sizeof(int) * DEFAULT_CAPACITY);
	seq->capacity = DEFAULT_CAPACITY;
	seq->size = 0;
}
//扩容的时间复杂度为0（n）
//扩容的空间复杂度一般不考虑
static void ensurecapacity(SeqList* seq)
{
	if (seq->size < seq->capacity)
	{
		return;
	}
	//通常来说，申请的新空间大小为旧空间的1.5-2倍
	int newCapacity = 2 * seq->capacity;
	int* newArray = (int*)malloc(sizeof(int) * newCapacity);
	for (int i = 0; i < seq->size; i++)
	{
		newArray[i] = seq->array[i];
	}
	free(seq->array);
	seq->array = newArray;
}
//销毁的时间复杂度也为0（1）
void SeqListDestroy(SeqList* seq)
{
	free(seq->array);
	seq->capacity = 0;
	seq->size = 0;
}
//头插的时间复杂度为0（n）
void SeqListPushFront(SeqList* seq, int val)
{
	for (int i = seq->size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->size++;
}
//尾插的时间复杂度为0（1）
//如果发生扩容就是0（n），没有发生扩容就是0（1）
void SeqListPushBack(SeqList* seq, int val)
{
	//先不考虑放不下的问题
	seq->array[seq->size] = val;
	seq->size++;
}
//根据下标做插入
//时间复杂度为0（n）
void SeqListInsert(SeqList* seq, int index, int val)
{
	//首先判断下表的合法性
	if (index<0 || index>seq->size)
	{
		printf("输入下标非法，请重新输入\n");
	}
	for (int i = seq->size; i > index; i--)
	{
		seq->array[i] = seq->array[i - 1];
	}
	seq->array[index] = val;
	seq->size++;
}
//打印的时间复杂度为0（n）
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
	//函数调用合法性的校验
	if (seq->size <= 0)
	{
		printf("空的\n");
		return;
	}
	//assert(seq->size)>0
	seq->size--;
}
//头删
void SeqListPopFront(SeqList* seq)
{
	for (int i = 0; i <= seq->size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
//根据下标删除
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
//时间复杂度和空间复杂度都是0（n）
void SeqListRemoveAll(SeqList* seq, int val)
{
	//可以使用额外的空间，要求时间上快点
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
//删完之后，顺序表中还剩多少个数？
//还剩j个数