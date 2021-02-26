#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef int BTNodeDataType;


typedef struct BTNode
{
	int data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;


void PreOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

BTNode* CreateNode(int data);

//树的销毁操作
void DestroyTree(BTNode** root);

//二叉树中结点的个数
int GetNodeCount(BTNode* root);

//二叉树中叶子结点的个数
int GetLeafNodeCount(BTNode* root);

//二叉树中第k层结点的个数
int GetKLevelNodeCount(BTNode* root,int k);

//二叉树中进行结点的查找
BTNode* TreeFind(BTNode* root, BTNodeDataType data);

//求二叉树的高度
int GetHeight(BTNode* root);

//判断一棵树是不是完全二叉树
int BinaryTreeComplete(BTNode* root);




/////////////////////////
void TestBinTree();
