#pragma once 


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
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

void NodePopFront(Node* head);

void NodePopBack(Node* head);

void NodePrint(Node* head);

void NodeInsert(Node* pos,int data);

void NodeErase(Node* pos);

Node *NodeFind(Node* head,int data);