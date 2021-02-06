#include"Seq.h"



void SeqListInit(SeqList* seq)
{
	assert(seq);
	seq->array = (int*)malloc(sizeof(int) * Default_Capacity);
	if (NULL == seq->array)
	{
		assert(0);
		return;
	}
	seq->_capacity = Default_Capacity;
	seq->_size = 0;
}

void SeqListDestroy(SeqList* seq)
{
	assert(seq);
	free(seq->array);
	seq->array = NULL;
	seq->_capacity = 0;
	seq->_size = 0;
}

void SeqListPushBack(SeqList* seq, int data)
{
	assert(seq);
	seq->array[seq->_size] = data;
	seq->_size++;
}

void SeqListPushFront(SeqList* seq, int data)
{
	assert(seq);
	for (int i = seq->_size - 1; i >= 0; --i)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = data;
	seq->_size++;
}

void SeqListPopFront(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i <= seq->_size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->_size--;
}

void SeqListPopBack(SeqList* seq)
{
	assert(seq);
	if (seq->_size == 0)
		return;
	seq->_size--;
}

void SeqListPrint(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i < seq->_size; i++)
	{
		printf("%d--->", seq->array[i]);
	}
	printf("NULL\n");
}
