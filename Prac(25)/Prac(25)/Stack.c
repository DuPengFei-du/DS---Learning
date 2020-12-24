#include"Stack.h"


void StackInit(Stack* s)
{
	assert(s);
	s->array = (int*)malloc(sizeof(int) * _Default_Capacity);
	if (NULL == s->array)
	{
		assert(0);
		return;
	}
	s->_capacity = _Default_Capacity;
	s->_size = 0;
}

void StackDestroy(Stack* s)
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->_capacity = 0;
	s->_size = 0;
}

void CheckCapacity(Stack* s)
{
	if (s->_capacity == s->_size)
	{
		int newcapacity = 2 * _Default_Capacity;
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

void StackPush(Stack* s, int data)
{
	assert(s);
	CheckCapacity(s);
	s->array[s->_size] = data;
	s->_size++;
}

void StackPop(Stack* s)
{
	assert(s);
	if (0 == s->_size)
		return;
	s->_size--;
}

int StackTop(Stack* s)
{
	assert(s);
	return s->array[s->_size - 1];
}

int StackSize(Stack* s)
{
	assert(s);
	return s->_size;
}

int StackEmpty(Stack* s)
{
	assert(s);
	return 0 == s->_size;
}