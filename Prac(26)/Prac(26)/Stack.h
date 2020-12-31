#pragma once 


#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdio.h>


#define Default_Capacity 100


typedef struct Stack
{
	int* array;
	int _size;
	int _capacity;
}Stack;


void StackInit(Stack* s);

void StackDestory(Stack* s);

void StackPush(Stack* s,int data);

void StackPop(Stack* s);

int StackEmpty(Stack* s);

int StackTop(Stack* s);

int StackSize(Stack* s);