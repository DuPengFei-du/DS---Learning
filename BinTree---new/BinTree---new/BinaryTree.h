#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef int BTNDataTye;


typedef struct BTNode
{
	BTNDataTye data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;


void PreOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

BTNode* CreateNode(BTNDataTye data);



////////////////////////////////////
void TestBinTree();