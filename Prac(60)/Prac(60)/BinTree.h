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

//�������н��Ĵ���
BTNode* CreateNode(int data);

//�����������ٲ���
void DestroyTree(BTNode** root);

//��ȡ�������н��ĸ���
int GetNodeCount(BTNode* root);

//��ȡ��������Ҷ�ӽ��ĸ���
int GetLeafNodeCount(BTNode* root);

//��ȡ��������k����ĸ���
int GetKLevelNodeCount(BTNode* root,int k);

//�ڶ������н��н��Ĳ���
BTNode* Find(BTNode* root, BTNDataType data);

//�ж�һ�����ǲ�����ȫ������
int IsBinaryTreeComplete(BTNode* root);

//�������Ŀ�������
BTNode *CopyTree(BTNode* root);

/////////////////////////////////////
void TestBinTree();