#pragma  once 


#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Default_Capacity 100


typedef struct Stack
{
	int* array;
	int _top;
	int _capacity;
}Stack;


void StackInit(Stack* s);

void StackDestroy(Stack* s);

void StackPush(Stack* s,int data);

void StackPop(Stack* s);

int StackTop(Stack* s);

int StackEmpty(Stack* s); 

int StackSize(Stack* s);