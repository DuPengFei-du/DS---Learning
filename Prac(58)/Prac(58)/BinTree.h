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

//�������н��Ĵ���
BTNode* CreateNode(int data);

//�������
//void LevelOrder(BTNode* root);

void DestroyTree(BTNode** root);

//��ȡ�������н��ĸ���
int GetNodeCount(BTNode* root);

//��ȡ��������Ҷ�ӽ��ĸ���
int GetLeafNodeCount(BTNode* root);

//��ȡ��������k����ĸ���
int GetKLevelNodeCount(BTNode* root,int k);

//�ڶ������н��н��Ĳ���
BTNode* Find(BTNode* root, BTNDataType data);

//////////////////////////////////
void TestBinTree();