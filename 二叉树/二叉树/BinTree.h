#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int BTDataType;

typedef struct BinTreeNode
{
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	BTDataType val;
}BTNode;

void PreOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

//获取二叉树中结点的个数
int GetNodeCount(BTNode* root);

//获取二叉树中叶子结点的个数
int GetLeafCount(BTNode* root);

//获取第K层中结点的个数
int GetKLevelCount(BTNode* root,int k);

//获取二叉树的高度
int GetHeight(BTNode* root);

//查找结点
BTNode* Find(BTNode* root, BTDataType x);

//获取双亲
BTNode* GetParent(BTNode* root, BTNode* pNode);


//创建二叉树，但是这种创建的方式并不是真正意义上创建二叉树的方式
//这种创建的方式只是为了验证所给的二叉树中的方法是否正确
BTNode* CreateBinTree();

BTNode* BuyBinTreeNode(BTDataType val);

//测试
void TestBinTree();