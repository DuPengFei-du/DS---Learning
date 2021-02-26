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

////二叉树的层序遍历
//void LevelOrder(BTNode* root)
//{
//	//二叉树的层序遍历需要用到队列的这种结构才可以 
//	Queue q;
//
//	if (root == NULL)
//		return;
//
//	QueueInit(&q);
//	QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* cur = QueueFront(&q);
//		printf("%d ", cur->data);
//
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
//
//	//用完了之后，记得要把队列销毁掉才可以
//	QueueDestroy(&q);
//}

//int BinaryTreeComplete(BTNode* root)
//{
//	Queue q;
//
//	int flag = 0;
//	int ret = 0;
//
//
//	//空树也是完全二叉树
//	if (root == NULL)
//		return 1;
//
//	//如果非空的话，那么就先把根节点放进去
//  QueueInit(&q);
//	QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* cur = QueueFront(&q);
//
//		if (flag)
//		{
//			//后续的结点都不能有孩子
//			if (cur->left || cur->right)
//				break;
//		}
//		else   //就去找第一个不饱和的结点
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
//				 break;
//			}
//			else
//			{
//				flag = 1;
//			}
//		}
//
//		QueuePop(&q);//把元素拿出来之后，让循环继续进行
//	}
//	
//	if (QueueEmptu(&q))
//		ret = 1;
//
//	QueueDestroy(&q);
//
//	return ret;
//}

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

//创建出来一棵假想的树出来
BTNode* CreateBinTree()
{
	BTNode* root = NULL;

	//给出六个结点出来
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

//二叉树中结点的个数
int GetNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + GetNodeCount(root->left) + GetNodeCount(root->right);
}

//二叉树中叶子结点的个数
int GetLeafNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}

//二叉树中第k层结点的个数
int GetKLevelNodeCount(BTNode* root,int k)
{
	if (root == NULL || k == 0)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}

BTNode* TreeFind(BTNode* root, BTNodeDataType data)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->data == data)
		return root;
	(ret = TreeFind(root->left, data)) || (ret = TreeFind(root->right, data));
	return ret;
}

int GetHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}


void DestroyTree(BTNode** root)
{
	assert(root);
	if (*root)
	{
		DestroyTree(&(*root)->left);
		DestroyTree(&(*root)->left);
		free(*root);
		*root = NULL;
	}
}



//////////////////////////////////
void TestBinTree()
{
	BTNode* root = CreateBinTree();

	printf("前序遍历的结果为：\n");
	PreOrder(root);
	printf("\n");

	printf("中序遍历的结果为：\n");
	InOrder(root);
	printf("\n");

	printf("后序遍历的结果为：\n");
	PostOrder(root);
	printf("\n");

	printf("二叉树中结点的个数为: %d \n", GetNodeCount(root));

	printf("二叉树中结点的个数为: %d \n", GetLeafNodeCount(root));

	BTNode* ret = TreeFind(root, 3);
	if (ret)
		printf("3 is in the tree\n");
	else 
		printf("3 is not in the tree\n");

	printf("二叉树的高度为: %d \n", GetHeight(root));

	DestroyTree(&root);
}