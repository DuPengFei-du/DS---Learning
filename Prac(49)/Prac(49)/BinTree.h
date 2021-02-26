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

//�������ٲ���
void DestroyTree(BTNode** root);

//�������н��ĸ���
int GetNodeCount(BTNode* root);

//��������Ҷ�ӽ��ĸ���
int GetLeafNodeCount(BTNode* root);

//�������е�k����ĸ���
int GetKLevelNodeCount(BTNode* root,int k);

//�������н��н��Ĳ���
BTNode* TreeFind(BTNode* root, BTNodeDataType data);

//��������ĸ߶�
int GetHeight(BTNode* root);

//�ж�һ�����ǲ�����ȫ������
int BinaryTreeComplete(BTNode* root);




/////////////////////////
void TestBinTree();
