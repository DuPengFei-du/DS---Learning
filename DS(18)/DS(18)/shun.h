#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

//¾²Ì¬Ë³Ðò±í
//typedef struct SeqList
//{
//	int arr[100];
//	int _size;
//	int _capacity;
//}SeqList;

//¶¯Ì¬Ë³Ðò±í 
#define Default_Capacity 100

typedef struct SeqList
{
	int* array;
	int _size;
	int capacity;
}SeqList;

//³õÊ¼»¯
void SeqListInit(SeqList* seq);

//Ïú»Ù
void SeqDestroy(SeqList* seq);

//Î²²å
void SeqListPushBack(SeqList* seq,int data);

//´òÓ¡
void SeqListPrint(SeqList* seq);

//Î²É¾
void SeqListPopBack(SeqList* seq);

//Í·²å
void SeqListPushFront(SeqList* seq, int data);

//Í·É¾
void SeqListPopFront(SeqList* seq);
