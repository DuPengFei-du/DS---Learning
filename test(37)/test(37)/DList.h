#pragma once


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


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

Node *NodeFind(Node* head,int data);

void NodeErase(Node* pos);