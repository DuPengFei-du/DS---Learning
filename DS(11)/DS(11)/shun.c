#include"shun.h"


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

void CheakCapacity(SeqList* seq)
{
	assert(seq);
	if (seq->_size == seq->_capacity)
	{
		//表明已经没有空间了
		int newcapacity = 2 * Default_Capacity;
		int* temp = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, seq->array, sizeof(int) * seq->_size);
		free(seq->array);
		seq->array = temp;
		seq->_capacity = newcapacity;
	}
}


void SeqListPushBack(SeqList* seq, int val)
{
	assert(seq);
	CheakCapacity(seq);
	seq->array[seq->_size] = val;
	seq->_size++;
}

void SeqListPopBack(SeqList* seq)
{
	assert(seq);
	if (0 == seq->_size)
		return;
	seq->_size--;
}

void SeqListPrint(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i < seq->_size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
	return ;
}

void SeqListPushFront(SeqList* seq, int val)
{
	assert(seq);
	//只要是插入，都需要检查一下容量
	CheakCapacity(seq);
	for (int i = seq->_size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->_size++;
}