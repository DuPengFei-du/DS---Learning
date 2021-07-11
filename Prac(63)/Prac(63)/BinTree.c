#include"BinTree.h"


void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}

////层序遍历需要用到队列的结构
//void LevelOrder(BTNode* root)
//{
//	//层序遍历需要借助队列这种数据结构
//	Queue q;
//
//	QueueInit(&q);
//
//	QueuePush(&q, root);
//
//	while (!QueueEmpty(&q))
//	{
//		BTNode* cur = QueueFront(&q);
//		printf("%d ", cur->data);
//		QueueFront(&q);
//		if (cur->left)
//		{
//			QueuePush(&q, cur->left);
//		}
//		if (cur->right)
//		{
//			QueuePush(&q, cur->right);
//		}
//	}
//	//用完队列了，记得把队列销毁掉
//	QueueDestroy(&q);
//}

//获取二叉树中结点的个数
int GetNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + GetNodeCount(root->left) + GetNodeCount(root->right);
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
	if (root == NULL || k < 0)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}

//获取二叉树的高度
int GetHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

////判断一棵树是否是完全二叉树
//int BinaryTreeComplete(BTNode* root)
//{
//	//需要借助到队列这种数据结构
//	Queue q;
//
//	if (root == NULL)
//		return 1;
//	int flag = 0;
//	int ret = 0;
//	QueueInit(&q);
//	QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* cur = QueueFront(&q);
//
//		if (flag)
//		{
//			if (cur->left || cur->right)
//				break;
//		}
//		else
//		{
//			if (cur->left && cur->right)
//			{
//				QueuePush(&q, cur->left);
//				QueuePush(&q, cur->right);
//			}
//			else if (cur->left)
//			{
//				QueuePush(&q, cur->left);
//				flag = 1;
//			}
//			else if (cur->right)
//			{
//				break;
//			}
//			else
//			{
//				flag = 1;
//			}
//		}
//		QueuePop(&q);
//	}
//	if (QueueEmpty(&q))
//		ret = 1;
//	QueueDestroy(&q);
//	return ret;
//}

//在二叉树中进行结点的查找
BTNode* Find(BTNode* root, BTNDataTpye data)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->data == data)
		return root;
	(ret = Find(root->left, data)) || (ret = Find(root->right, data));
	return ret;
}

//二叉树中结点的创建
BTNode* CreateNode(BTNDataTpye data)
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

//二叉树的销毁操作
void DestroyTree(BTNode** root)
{
	assert(root);
	if (*root)
	{
		DestroyTree(&(*root)->left);
		DestroyTree(&(*root)->right);
		free(*root);
		*root = NULL;
	}
}

//二叉树的拷贝操纵
BTNode* CopyBinTree(BTNode* root)
{
	BTNode* NewRoot = NULL;
	if (root)
	{
		NewRoot = CreateNode(root->data);
		NewRoot->left = CopyBinTree(root->left);
		NewRoot->right = CopyBinTree(root->right);
	}
	return NewRoot;
}

//二叉树的创建
BTNode* CreateBinaryTree(int array[], int size, int* index, int invalid)
{
	BTNode* root = NULL;

	if (*index < size && invalid != array[*index])
	{
		root = CreateNode(array[*index]);

		//然后去创建根节点的左子树
		++(*index);
		root->left = CreateBinaryTree(array, size, index, invalid);

		//然后去创建根节点的右子树
		++(*index);
		root->right = CreateBinaryTree(array, size, index, invalid);
	}
	return root;
}




void TestBinTree()
{
	int array[] = { 1,2,3,-1,-1,-1,4,5,-1,-1,6 };

	int index = 0;

	BTNode* root = CreateBinaryTree(array, sizeof(array) / sizeof(array[0]), &index, -1);

	BTNode* NewRoot = NULL;

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

	//用root来拷贝这棵新的树

	NewRoot = CopyBinTree(root);

	printf("前序遍历结果为:\n");
	PreOrder(root);
	printf("\n");

	printf("中序遍历结果为:\n");
	InOrder(root);
	printf("\n");

	printf("后序遍历结果为:\n");
	PostOrder(root);
	printf("\n");

	DestroyTree(&root);

	DestroyTree(&NewRoot);

}