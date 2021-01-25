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

//那么，现在，如果我们想要验证一下这几种方法是否是正确的，那么我们就可以先
//利用一种不那么正规的创建树的形式，我们先创建出来一棵树，从而对遍历的结果进行验证的操作
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
//二叉树先简单的构造好之后就可以进行一系列的操作了

void TestBinTree()
{
	BTNode* root = CreateBinaryTree();
	printf("前序遍历结果为:\n");
	PreOrder(root);
	printf("\n");

	printf("中序遍历结果为:\n");
	InOrder(root);
	printf("\n");

	printf("后序遍历结果为:\n");
	PostOrder(root);
	printf("\n");

}