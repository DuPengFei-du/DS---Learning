#include"Stack.h"


void StackInit(Stack* s)
{
	assert(s);
	s->array = (int*)malloc(sizeof(int) * Default_Capacity);
	if (NULL == s->array)
	{
		assert(0);
		return;
	}
	s->_top = 0;
	s->_capacity = Default_Capacity;
}

void StackDestroy(Stack* s)
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->_top = 0;
	s->_capacity = 0;
}

void CheckCapacity(Stack* s)
{
	assert(s);
	if (s->_capacity == s->_top)
	{
		int newcapacity = 2 * Default_Capacity;
		int* temp = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, s->array, sizeof(int) * s->_top);
		free(s->array);
		s->array = temp;
		s->_capacity = newcapacity;
	}
}

void StackPush(Stack* s, int data)
{
	assert(s);
	CheckCapacity(s);
	s->array[s->_top] = data;
	s->_top++;
}

void StackPop(Stack* s)
{
	assert(s);
	s->_top--;
}

int StackEmpty(Stack* s)
{
	assert(s);
	return 0 == s->_top;
}

int StackTop(Stack* s)
{
	assert(s);
	return s->array[s->_top-1];
}

int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}