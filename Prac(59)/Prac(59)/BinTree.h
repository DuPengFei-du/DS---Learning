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

//层序遍历需要用到队列的结构
//void LevelOrder(BTNode* root);

//获取二叉树中结点的个数
int GetNodeCount(BTNode* root);

//获取二叉树中叶子结点的个数
int GetLeafNodeCount(BTNode* root);

//获取二叉树第k层结点的个数
int GetKLevelNodeCount(BTNode* root, unsigned int k);

//获取二叉树的高度
int GetHeight(BTNode* root);

//判断一棵树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);

//在二叉树中进行结点的查找
BTNode* Find(BTNode* root, BTNDataTye data);

//二叉树中结点的创建
BTNode* CreateNode(BTNDataTye data);

//二叉树的销毁操作
void DestroyTree(BTNode** root);

void TestBinTree();

