#pragma once 

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef int BTNDataType;


typedef struct BinTreeNode
{
	BTNDataType data;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}TreeNode;


void PreOrder(TreeNode* root);

void InOrder(TreeNode* root); 

void PostOrder(TreeNode* root);

//层序遍历
//void LevelOrder(TreeNode* root);

//二叉树中结点的创建
TreeNode* CreateNode(BTNDataType data);



//////////////////////////////////////
void TestBinTree();