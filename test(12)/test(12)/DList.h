#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


typedef struct DLNode
{
	int data;
	struct DLNode* next;
	struct DLNode* prev;
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