#include"shun.h"

void SeqListInit(SeqList* seq)
{
	assert(seq != NULL);  //先检测参数的合法性，然后再给出算法的功能
	seq->array = (int*)malloc(sizeof(int) * Default_Capacity);
	if (NULL == seq->array)
	{
		assert(0);  //assert是调试宏，只有在Debug版本才能起作用
		return;
	}
	//如果if不成立，说明申请空间已经成功了
	seq->_size = 0;
	seq->_capacity = Default_Capacity;
}

void SeqListDestroy(SeqList* seq)
{
	free(seq->array);
	seq->array = NULL;
	seq->_size = 0;
	seq->_capacity = 0;
}

void SeqListPrint(SeqList* seq)
{
	for (int i = 0; i < seq->_size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
}

void CheckCapacity(SeqList* seq)
{
	assert(seq);
	if (seq->_capacity == seq->_size)
	{
		int newcapacity = 2 * Default_Capacity;
		int* temp = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, seq->array, seq->_size * sizeof(int));
		free(seq->array);
		seq->array = temp;
		seq->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* seq, int data)
{
	assert(seq);
	CheckCapacity(seq);
	seq->array[seq->_size] = data;
	seq->_size++;
}

void SeqListPopBack(SeqList* seq)
{
	assert(seq);
	if (0 == seq->_size)
		return;
	seq->_size--;
}

void SeqListPushFront(SeqList* seq, int data)
{
	assert(seq);
	CheckCapacity(seq);
	for (int i = seq->_size - 1; i >= 0; i--)
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

void SeqListInsert(SeqList* seq, int index, int data)
{
	assert(seq);
	CheckCapacity(seq);
	if (index<0 || index>seq->_size)
		printf("输入下标有误，请重新输入!\n");
	for (int i = seq->_size - 1; i >= index; --i)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[index] = data;
	seq->_size++;
}

void SeqListErase(SeqList* seq, int index)
{
	assert(seq);
	for (int i = index; i <= seq->_size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->_size--;
}