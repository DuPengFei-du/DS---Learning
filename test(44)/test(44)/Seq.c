#include"Seq.h"


void SeqListInit(SeqList* s)
{
	assert(s);
	s->array = (int*)malloc(sizeof(int) * Default_Capacity);
	if (NULL == s->array)
	{
		assert(0);
		return;
	}
	s->_capacity = 0;
	s->_size = 0;
}

void SeqListDestroy(SeqList* s)
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->_capacity = 0;
	s->_size = 0;
}

void CheckCapacity(SeqList* s)
{
	if (s->_size == s->_capacity)
	{
		int newcapacity = 2 * Default_Capacity;
		int* temp = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, s->array, sizeof(int) * s->_size);
		free(s->array);
		s->array = temp;
		s->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* s, int data)
{
	assert(s);
	CheckCapacity(s);
	s->array[s->_size] = data;
	s->_size++;
}

void SeqListPushFront(SeqList* s, int data)
{
	assert(s);
	for (int i = s->_size; i >= 0; --i)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[0] = data;
	s->_size++;
}

void SeqListPopBack(SeqList* s)
{
	assert(s);
	if (s->_size == 0)
		return;
	s->_size--;
}

void SeqListPopFront(SeqList* s)
{
	assert(s);
	for (int i = 0; i < s->_size; i++)
	{
		s->array[i] = s->array[i + 1];
	}
	s->_size--;
}

void SeqListPrint(SeqList* s)
{
	assert(s);
	for (int i = 0; i < s->_size; i++)
	{
		printf("%d--->", s->array[i]);
	}
	printf("NULL\n");
}

void SeqListInsert(SeqList* s, int index, int data)
{
	assert(s);
	for (int i = s->_size; i >= index; --i)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[index] = data;
	s->_size++;
}

void SeqListErase(SeqList* s, int index)
{
	assert(s);
	for (int i = index; i<=s->_size-2; ++i)
	{
		s->array[i] = s->array[i+1];
	}
	s->_size--;
}

int SeqListFind(SeqList* s, int data)
{
	assert(s);
	for (int i = 0; i < s->_size; i++)
	{
		if (s->array[i] == data)
			return i;
	}
	return -1;
}