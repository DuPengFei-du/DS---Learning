#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef int BTNDataType;


typedef struct BTNode
{
	BTNDataType data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;


void PreOrder(BTNode* root);

void InOrder(BTNode* root); 

void PostOrder(BTNode* root);

//void LevelOrder(BTNode* root);

BTNode* CreateNode(BTNDataType data);

void DestroyTree(BTNode** root);


////////////////////////////////
void TestBinTree();