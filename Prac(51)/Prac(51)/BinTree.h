#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef int BTNDataType;


typedef struct BinTreeNode
{
	int data;
	struct BinTreeNode* left;
	struct BinTreeNode* right;

}BTNode;


void PreOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

void LevelOrder(BTNode* root);

BTNode* CreateNode(int data);

//二叉树的销毁操作
void DestroyTree(BTNode** root);

//获取二叉树中结点的个数
int GetNodeCount(BTNode* root);

//获取二叉树中叶子结点的个数
int GetLeafNodeCount(BTNode* root);

//获取二叉树中第k层的个数
int GetKLevelNodeCount(BTNode* root,int k);

//二叉树中结点的查找
BTNode* TreeFind(BTNode* root, BTNDataType data);

//求二叉树的高度
int GetHeight(BTNode* root);

//判断一棵树是不是完全二叉树
int IsBinaryTreeComplete(BTNode* root);



/////////////////////////
void TestBinTree();