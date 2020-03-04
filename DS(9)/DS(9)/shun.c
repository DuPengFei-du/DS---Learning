#include"shun.h"


void SeqListInit(SeqList* seq)
{
	//进来需要先看一下这个顺序表是否存在
	assert(seq);
	seq->array = (int*)malloc(sizeof(int) * Default_Capacity);
	//开辟空间了，我接下来需要看一下我开辟的空间是否开辟成功了
	if (NULL == seq->array)
	{
		assert(0);
		return NULL;
	}
	seq->size = 0;
	seq->capacity = Default_Capacity;
}

void CheckCapacity(SeqList* seq)
{
	assert(seq);
	if (seq->size = seq->capacity)
	{
		//证明没有空间了，需要扩容了
		int newcapacity = 2 * Default_Capacity;
		int* NewArray = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == NewArray)
		{
			assert(0);
			return;
		}
		memcpy(NewArray, seq->array, sizeof(int) * seq->size);
		//释放旧空间
		free(seq->array);
		seq->array = NewArray;
		seq->capacity = newcapacity;
	}
}

void SeqListDestroy(SeqList* seq)
{
	free(seq->array);
	//释放了之后，我还需要把它设置成空值
	seq->array = NULL;
	seq->capacity = 0;
	seq->size = 0;
}