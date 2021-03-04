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

//�����������ٲ���
void DestroyTree(BTNode** root);

//��ȡ�������н��ĸ���
int GetNodeCount(BTNode* root);

//��ȡ��������Ҷ�ӽ��ĸ���
int GetLeafNodeCount(BTNode* root);

//��ȡ�������е�k��ĸ���
int GetKLevelNodeCount(BTNode* root,int k);

//�������н��Ĳ���
BTNode* TreeFind(BTNode* root, BTNDataType data);

//��������ĸ߶�
int GetHeight(BTNode* root);

//�ж�һ�����ǲ�����ȫ������
int IsBinaryTreeComplete(BTNode* root);



/////////////////////////
void TestBinTree();