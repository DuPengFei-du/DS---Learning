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
	s->_capacity = Default_Capacity;
	s->top = 0;
}

void StackDestroy(Stack* s)
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->top = 0;
	s->_capacity = 0;
}

void CheckCapacity(Stack* s)
{
	assert(s);
	if (s->top == s->_capacity)
	{
		int newcapacity = 2 * Default_Capacity;
		int* temp = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, s->array, sizeof(int) * s->top);
		free(s->array);
		s->array = temp;
		s->_capacity = newcapacity;
	}
}

void StackPush(Stack* s, int data)
{
	assert(s);
	CheckCapacity(s);
	s->array[s->top] = data;
	s->top++;
}

void StackPop(Stack* s)
{
	assert(s);
	if (0 == s->top)
		return;
	s->top--;
}

int StackSize(Stack* s)
{
	assert(s);
	return s->top;
}

int StackTop(Stack* s)
{
	assert(s);
	return s->array[s->top - 1];
}

int StackEmpty(Stack* s)
{
	assert(s);
	if (0 == s->top)
		return 1;
	return 0;
}