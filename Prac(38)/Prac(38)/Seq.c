#include"Seq.h"


void SeqListInit(Seq* s)
{
	assert(s);
	s->array = (int*)malloc(sizeof(int) * Default_Capacity);
	if (NULL == s->array)
	{
		assert(0);
		return;
	}
	s->_capacity = Default_Capacity;
	s->_size = 0;
}

void SeqListDestroy(Seq* s)
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->_capacity = 0;
	s->_size = 0;
}

void CheckCpacity(Seq* s)
{
	assert(s);
	if (s->_capacity == s->_size)
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

void SeqListPushBack(Seq* s, int data)
{
	assert(s);
	CheckCpacity(s);
	s->array[s->_size] = data;
	s->_size++;
}

void SeqListPushFront(Seq* s, int data)
{
	assert(s);
	for (int i = s->_size - 1; i >= 0; --i)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[0] = data;
	s->_size++;
}

void SeqListPopFront(Seq* s)
{
	assert(s);
	for (int i = 0; i <= s->_size - 2; i++)
	{
		s->array[i] = s->array[i + 1];
	}
	s->_size--;
}

void SeqListPopBack(Seq* s)
{
	assert(s);
	if (0 == s->_size)
		return;
	s->_size--;
}

void SeqListPrint(Seq* s)
{
	assert(s);
	for (int i = 0; i < s->_size; i++)
	{
		printf("%d-->", s->array[i]);
	}
	printf("NULL\n");
}