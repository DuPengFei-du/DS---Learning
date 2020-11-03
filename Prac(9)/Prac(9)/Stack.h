#pragma once


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef struct Stack
{
	int* array;
	int _top;
	int _capacity;
}Stack;


#define Default_Capcity 100


void StackInit(Stack* s);

void StackDestroy(Stack* s);

void StackPush(Stack* s,int data);

void StackPop(Stack* s);

int StacTop(Stack* s);

int StackEmpty(Stack* s);

int StackSize(Stack* s);
