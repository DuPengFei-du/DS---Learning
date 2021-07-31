#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef struct DListNode
{
	int data;
	struct DListNode* next;
	struct DListNode* prev;
}Node;


void NodeInit(Node** head);

void NodeDestroy(Node** head);

void NodePushBack(Node* head,int data);

void NodePushFront(Node* head, int data);

void NodePopBack(Node* head);

void NodePopFront(Node* head);

void NodePrint(Node* head);

void NodeErase(Node* pos);

Node *NodeFind(Node* pos,int data);
