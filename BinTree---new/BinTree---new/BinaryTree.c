#include"BinaryTree.h"


void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d", root->data);
		InOrder(root->right);
	}
}

void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d", root->data);
	}
}

//��ô�����ڣ����������Ҫ��֤һ���⼸�ַ����Ƿ�����ȷ�ģ���ô���ǾͿ�����
//����һ�ֲ���ô����Ĵ���������ʽ�������ȴ�������һ�������Ӷ��Ա����Ľ��������֤�Ĳ���
BTNode* CreateNode(BTNDataTye data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->left = NULL;
	pNewNode->right = NULL;
	return pNewNode;
}

BTNode* CreateBinaryTree()
{
	BTNode* root = NULL;
	BTNode* n1 = CreateNode(1);
	BTNode* n2 = CreateNode(2);
	BTNode* n3 = CreateNode(3);
	BTNode* n4 = CreateNode(4);
	BTNode* n5 = CreateNode(5);
	BTNode* n6 = CreateNode(6);

	root = n1;
	root->left = n2;
	n2->left = n3;

	root->right = n4;
	n4->left = n5;
	n4->right = n6;

	return root;
}



//////////////////////////////////////////////
//�������ȼ򵥵Ĺ����֮��Ϳ��Խ���һϵ�еĲ�����

void TestBinTree()
{
	BTNode* root = CreateBinaryTree();
	printf("ǰ��������Ϊ:\n");
	PreOrder(root);
	printf("\n");

	printf("����������Ϊ:\n");
	InOrder(root);
	printf("\n");

	printf("����������Ϊ:\n");
	PostOrder(root);
	printf("\n");

}