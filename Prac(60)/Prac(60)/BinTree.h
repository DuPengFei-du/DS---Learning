#pragma once 


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


typedef int BTNDataType;


typedef struct BTNode
{
	int data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;


void PreOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

//void LevelOrder(BTNode* root);

//二叉树中结点的创建
BTNode* CreateNode(int data);

//二叉树的销毁操作
void DestroyTree(BTNode** root);

//获取二叉树中结点的个数
int GetNodeCount(BTNode* root);

//获取二叉树中叶子结点的个数
int GetLeafNodeCount(BTNode* root);

//获取二叉树第k层结点的个数
int GetKLevelNodeCount(BTNode* root,int k);

//在二叉树中进行结点的查找
BTNode* Find(BTNode* root, BTNDataType data);

//判断一棵树是不是完全二叉树
int IsBinaryTreeComplete(BTNode* root);

//二叉树的拷贝操作
BTNode *CopyTree(BTNode* root);

/////////////////////////////////////
void TestBinTree();