#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int BTNDataTpye;


typedef struct BTNode
{
	BTNDataTpye data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;

void PreOrder(BTNode* root);

void InOrder(BTNode* root);

void PostOrder(BTNode* root);

//���������Ҫ�õ����еĽṹ
//void LevelOrder(BTNode* root);

//��ȡ�������н��ĸ���
int GetNodeCount(BTNode* root);

//��ȡ��������Ҷ�ӽ��ĸ���
int GetLeafNodeCount(BTNode* root);

//��ȡ��������k����ĸ���
int GetKLevelNodeCount(BTNode* root, unsigned int k);

//��ȡ�������ĸ߶�
int GetHeight(BTNode* root);

//�ж�һ�����Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);

//�ڶ������н��н��Ĳ���
BTNode* Find(BTNode* root, BTNDataTpye data);

//�������н��Ĵ���
BTNode* CreateNode(BTNDataTpye data);

//�����������ٲ���
void DestroyTree(BTNode** root);

//�������Ŀ�������
BTNode* CopyBinTree(BTNode* root);

//�������Ĵ���
BTNode* CreateBinaryTree(int array[], int size, int* index, int invalid);



void TestBinTree();
