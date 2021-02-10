#pragma once 


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>



typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;


void ListInit(Node** head);

void ListDestroy(Node** head);

void ListPushBack(Node* head,int data);

void ListPushFront(Node* head, int data);

void ListPopFront(Node* head);

void ListPopBack(Node* head);

void ListPrint(Node* head);