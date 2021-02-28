#pragma once 


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef struct ListNode
{
	int data;
	struct ListNode* next;
	struct ListNode* prev;
}Node;


void NodeInit(Node** head);

void NodeDestroy(Node** head);

void NodePushBack(Node* head,int data);

void NodePushFront(Node* head, int data);

void NodePopBack(Node* head);

void NodePopFront(Node* head);

void NodePrint(Node* head);