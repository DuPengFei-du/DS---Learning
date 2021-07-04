#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>



typedef struct ListNode
{
	int data;
	struct ListNode* prev;
	struct ListNode* next;
}Node;


void ListInit(Node** head);

void ListDestroy(Node** head);

void ListPushBack(Node* head,int data);

void ListPushFront(Node* head, int data);

void ListPopFront(Node* head);

void ListPopBack(Node* head);

void ListPrint(Node* head);
