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

//二叉树中结点的创建
BTNode* CreateNode(int data);

//层序遍历
//void LevelOrder(BTNode* root);

void DestroyTree(BTNode** root);

//获取二叉树中结点的个数
int GetNodeCount(BTNode* root);

//获取二叉树中叶子结点的个数
int GetLeafNodeCount(BTNode* root);

//获取二叉树第k层结点的个数
int GetKLevelNodeCount(BTNode* root,int k);

//在二叉树中进行结点的查找
BTNode* Find(BTNode* root, BTNDataType data);

//////////////////////////////////
void TestBinTree();