#pragma once


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

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

int StackSize(Stack* s);

int StackTop(Stack* s);

int StackEmpty(Stack* s);
