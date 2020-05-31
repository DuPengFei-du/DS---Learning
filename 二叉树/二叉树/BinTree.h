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

//��ȡ�������н��ĸ���
int GetNodeCount(BTNode* root);

//��ȡ��������Ҷ�ӽ��ĸ���
int GetLeafCount(BTNode* root);

//��ȡ��K���н��ĸ���
int GetKLevelCount(BTNode* root,int k);

//��ȡ�������ĸ߶�
int GetHeight(BTNode* root);

//���ҽ��
BTNode* Find(BTNode* root, BTDataType x);

//��ȡ˫��
BTNode* GetParent(BTNode* root, BTNode* pNode);


//�������������������ִ����ķ�ʽ���������������ϴ����������ķ�ʽ
//���ִ����ķ�ʽֻ��Ϊ����֤�����Ķ������еķ����Ƿ���ȷ
BTNode* CreateBinTree();

BTNode* BuyBinTreeNode(BTDataType val);

//����
void TestBinTree();