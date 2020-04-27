#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>



typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	char data;
}BTNode;


//提供给外部用户
//创建二叉树
BTNode* CreateBinTree(BTDataType* array, int size);

//二叉树的遍历方式
//前序遍历
void PreOrder(BTNode* pRoot);
//void PreOrderNor(BTNode* pRoot);   //循环的方式

//中序遍历
void InOrder(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);


//后序遍历
void PostOrder(BTNode* pRoot);
void PostOrderNor(BTNode* pRoot);


//层序遍历
//void LevelOrder(BTNode* pRoot);

//获取二叉树中结点的个数
int GetNodeCount(BTNode* pRoot);

//求二叉树的高度
int Height(BTNode* pRoot);

//是否为平衡二叉树
int IsBalanceTree(BTNode* pRoot);   //这个方法的时间复杂度是O(N^2)
int IsBalanceTreeII(BTNode* pRoot,int *height);     //这个方法的时间复杂度是0(N)

//二叉树的销毁
void DestroyBinTree(BTNode** pRoot);

//叶子结点的个数
int GetLeafNodeCount(BTNode* pRoot);

//第k层结点的个数
int GetKLevelNodeCount(BTNode* pRoot, int k);

//找一个结点的双亲
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);

//找节点
BTNode* GetNode(BTNode* pRoot, BTDataType data);   //在树种，找结点

//树的拷贝
BTNode* CopyBinTree(BTNode* pRoot);

//二叉树的镜像
void Mirror(BTNode* pRoot);

void MirrorNor(BTNode* pRoot);