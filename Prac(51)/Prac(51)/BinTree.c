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

//void LevelOrder(BTNode* root)
//{
//	//层序遍历需要借助队列的这种结构
//	Queue q;
//
//	if (root == NULL)
//		return;
//
//	//然后需要对队列进行初始化的操作
//	QueueInit(&q);
//
//	QueuePush(&q, root);
//
//	//不为空的话，循环需要一直进行
//	while (!QueueEmpty(&q))
//	{
//		BTNode* cur = QueueFront(&q);
//		printf("%d ", cur->data);
//		QueuePop(&q);
//
//		if (cur->left)
//		{
//			QueuePush(&q, cur->left);
//		}
//
//		if (cur->right)
//		{
//			QueuePush(&q, cur->right);
//		}
//	}
//	//用完之后记得将队列进行销毁的操作
//
//	QueueDestroy(&q);
//}

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

int GetNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + GetNodeCount(root->left) + GetNodeCount(root->right);
}

int GetLeafNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}

int GetKLevelNodeCount(BTNode* root, int k)
{
	if (root == NULL || k < 0)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}


BTNode* TreeFind(BTNode* root, BTNDataType data)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->data == data)
		return root;
	(ret = TreeFind(root->left,data)) || (ret = TreeFind(root->right,data));
	return ret;
}

//int IsBinaryTreeComplete(BTNode* root)
//{
//	Queue q;
//
//	int ret = 0;
//	int flag = 0;
//
//	if (root == NULL)
//		return 1;
//
//	QueueInit(&q);
//
//	QueuePush(&q, root);
//
//	while (!QueueEmpty(&q))
//	{
//		BTNode* cur = QueueFront(&q);
//
//		if (flag)
//		{
//			if (cur->left == NULL || cur->right == NULL)
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
//				//cur只有左孩子，那么现在临界的条件就找到了
//				QueuePush(cur->left);
//				flag = 1;
//			}
//			else if (cur->right)
//			{
//				//cur 只有右孩子
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
//
//	QueueDestroy(&q);
//
//	return ret;
//}


int GetHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}


BTNode* CreateNode(int data)
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

//先给出假象的创建树的一种方式
BTNode* CreateBinTree()//没有参数
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






//////////////////////////////////
void TestBinTree()
{
	BTNode* root = CreateBinTree();

	printf("前序遍历的结果为:>\n");
	PreOrder(root);
	printf("\n");

	printf("中序遍历的结果为:>\n");
	InOrder(root);
	printf("\n");

	printf("后序遍历的结果为:>\n");
	PostOrder(root);
	printf("\n");

	printf("树中结点的个数为: %d\n", GetNodeCount(root));

	printf("树中叶子结点的个数为: %d\n", GetLeafNodeCount(root));

	printf("树中第二层结点的个数为: %d\n", GetKLevelNodeCount(root,2));

	BTNode* cur = TreeFind(root, 3);
	if (cur)
	{
		printf("3 is in the tree\n");
	}
	else
	{
		printf("3 is not in the tree\n");

	}

	printf("树的高度为: %d\n", GetHeight(root));

	DestroyTree(&root);
}