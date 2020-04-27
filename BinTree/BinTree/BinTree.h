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


//�ṩ���ⲿ�û�
//����������
BTNode* CreateBinTree(BTDataType* array, int size);

//�������ı�����ʽ
//ǰ�����
void PreOrder(BTNode* pRoot);
//void PreOrderNor(BTNode* pRoot);   //ѭ���ķ�ʽ

//�������
void InOrder(BTNode* pRoot);
void InOrderNor(BTNode* pRoot);


//�������
void PostOrder(BTNode* pRoot);
void PostOrderNor(BTNode* pRoot);


//�������
//void LevelOrder(BTNode* pRoot);

//��ȡ�������н��ĸ���
int GetNodeCount(BTNode* pRoot);

//��������ĸ߶�
int Height(BTNode* pRoot);

//�Ƿ�Ϊƽ�������
int IsBalanceTree(BTNode* pRoot);   //���������ʱ�临�Ӷ���O(N^2)
int IsBalanceTreeII(BTNode* pRoot,int *height);     //���������ʱ�临�Ӷ���0(N)

//������������
void DestroyBinTree(BTNode** pRoot);

//Ҷ�ӽ��ĸ���
int GetLeafNodeCount(BTNode* pRoot);

//��k����ĸ���
int GetKLevelNodeCount(BTNode* pRoot, int k);

//��һ������˫��
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);

//�ҽڵ�
BTNode* GetNode(BTNode* pRoot, BTDataType data);   //�����֣��ҽ��

//���Ŀ���
BTNode* CopyBinTree(BTNode* pRoot);

//�������ľ���
void Mirror(BTNode* pRoot);

void MirrorNor(BTNode* pRoot);