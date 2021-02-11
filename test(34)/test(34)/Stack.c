#include"Stack.h"


void SeqListInit(SeqList* seq)
{
	assert(seq);
	seq->array = (int*)malloc(sizeof(int) * Default_Capacity);
	if (NULL == seq->array)
	{
		assert(0);
		return;
	}
	seq->capacity = Default_Capacity;
	seq->size = 0;
}

void SeqListDestroy(SeqList* seq)
{
	assert(seq);
	free(seq->array);
	seq->array = NULL;
	seq->capacity = 0;
	seq->size = 0;
}

void CheckCapacity(SeqList* seq)
{
	assert(seq);
	if (seq->capacity == seq->size)
	{
		int newcapacity = 2 * Default_Capacity;
		int* temp = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, seq->array, sizeof(int) * seq->size);
		free(seq->array);
		seq->array = temp;
		seq->capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* seq, int data)
{
	assert(seq);
	CheckCapacity(seq);
	seq->array[seq->size] = data;
	seq->size++;
}

void SeqListPushFront(SeqList* seq, int data)
{
	assert(seq);
	CheckCapacity(seq);
	for (int i = seq->size - 1; i >= 0; --i)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = data;
	seq->size++;
}

void SeqListPopFront(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i <= seq->size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

void SeqListPopBack(SeqList* seq)
{
	assert(seq);
	if (seq->size == 0)
		return;
	seq->size--;
}

void SeqListPrint(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i < seq->size; i++)
	{
		printf("%d--->", seq->array[i]);
	}
	printf("NULL\n");
}

void SeqListInsert(SeqList* seq, int index, int data)
{
	assert(seq);
	CheckCapacity(seq);
	for (int i = seq->size - 1; i >= index; --i)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[index] = data;
	seq->size++;
}

void SeqListErase(SeqList* seq, int index)
{
	assert(seq);
	for (int i = index; i <= seq->size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}