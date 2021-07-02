#include"BinTree.h"


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

//void LevelOrder(BTNode* root)
//{
//	Queue q;
//
//	//一进来之后，我们需要先检测一下树是不是为空的
//	if (root==NULL)
//	{
//		return;
//	}
//
//	//不空的话，正式开始操作
//	QueueInit(&q);
//	QueuePush(&q, root);
//
//	while (!QueueEmpty(&q))
//	{
//		BTNode* cur = QueueFront(&q);
//		printf("%d ", cur->data);
//		QueuePop(&q);
//		if (cur->left)
//		{
//			QueuePush(&q, cur->left);
//		}
//		if (cur->right)
//		{
//			QueuePush(&q, cur->right);
//		}
//	}
//	//循环走完之后，说明遍历结束
//	//记得最后要销毁
//	QueueDestroy(&q);
//}

//获取二叉树中结点的个数
int GetNodeCount(BTNode* root)
{
	/*if (root == NULL)
		return 0;
	int leftSize = GetNodeCount(root->left);
	int rightSize = GetNodeCount(root->right);
	return leftSize + rightSize + 1;*/

	if (root == NULL)
		return 0;
	else
		return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;

	//当然还可以使用计数器的方法
}

//获取二叉树中叶子结点的个数
int GetLeafNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}

//获取二叉树第k层结点的个数
int GetKLevelNodeCount(BTNode* root, unsigned int k)
{
	if (root == NULL || k == 0)
		return 0;
	if (k == 1)
		return 1;
	//如果现在想直接求二叉树第k层中结点的个数，那么其实是不好求的
	//所以我们讲其转换为子问题来进行求解
	//那么其实就是再求子树中第k-1层结点的个数
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}

//在二叉树中进行结点的查找
BTNode* Find(BTNode* root, BTNDataTye data)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->data == data)
		return root;
	(ret= Find(root->left, data)) || (ret = Find(root->right, data));
	return ret;
}

int GetHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftheigth = 0;
	int rightheight = 0;
	leftheigth = GetHeight(root->left);
	rightheight = GetHeight(root->right);
	return leftheigth > rightheight ? leftheigth + 1 : rightheight + 1;
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

void DestroyTree(BTNode** root)
{
	//你要销毁一棵树的话，那么这棵树，首先是要存在的
	//然后，你才能去销毁他
	assert(root);   //root中的内容其实就是外部实参的地址
	if (*root)      //*root才是外部的实参
	{
		DestroyTree(&(*root)->left);    //先解引用拿到值，然后再取地址，就得到地址了
		DestroyTree(&(*root)->right);
		free(*root);
		*root = NULL;
	}
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


//
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

	printf("树中结点的个数为:%d\n", GetNodeCount(root));

	printf("树中叶子结点的个数为:%d\n", GetLeafNodeCount(root));

	printf("树中第k层结点的个数为:%d\n", GetKLevelNodeCount(root, 3));

	BTNode* cur = Find(root, 4);
	if (cur != NULL)
	{
		printf("4 is in the tree\n");
	}
	else
	{
		printf("4 is not in the tree\n");
	}

	printf("树的高度为:%d\n", GetHeight(root));

	DestroyTree(&root);
}
