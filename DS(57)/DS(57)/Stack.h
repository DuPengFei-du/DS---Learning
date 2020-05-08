#pragma once 

#define Default_Capacity 100

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct Stack
{
	int* array;
	int _top;
	int _capacity;
}Stack;

void StakcInit(Stack* s);

void StakcDestroy(Stack* s);

void StakcPush(Stack* s,int data);

void StakcPop(Stack* s);

int StakcSize(Stack* s);

int StakcEmpty(Stack* s);

int StakcTop(Stack* s);






