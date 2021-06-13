#include"BinTree.h"


void PreOrder(TreeNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(TreeNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

void PostOrder(TreeNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}

//void LevelOrder(TreeNode* root)
//{
//	//层序遍历需要借助到队列的这种结构
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, root);
//
//	while (!QueueEmpty())
//	{
//		TreeNode* cur = QeueuFront(&q);
//		printf("%d ", cur->data);
//		QeueuPop(&q);
//		if (cur->left)
//		{
//			QueuePush(&q, cur->left);
//		}
//		if (cur->right)
//		{
//			QueuePush(&q, cur->right);
//		}
//
//	}
//	//用完了队列的结构之后，记得销毁这个队列
//	QueueDestroy(&q);
//}

TreeNode* CreateNode(BTNDataType data)
{
	TreeNode* pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode ->left = NULL;
	pNewNode ->right = NULL;
	return pNewNode;
}

//现在给出一种假想的创建树的方式，那么为什么是假想的创建树的方式呢
//因为这种方式只是通过开辟结点的空间，构造出来一颗我们希望去看到的
//树的形状，所以我们把这种创建树的方式称为假想的创建树的一种方式
TreeNode* CreateBinTree()
{
	TreeNode* root = NULL;

	TreeNode* n1 = CreateNode(1);
	TreeNode* n2 = CreateNode(2);
	TreeNode* n3 = CreateNode(3);
	TreeNode* n4 = CreateNode(4);
	TreeNode* n5 = CreateNode(5);
	TreeNode* n6 = CreateNode(6);

	root = n1;

	root->left = n2;
	n2->left = n3;

	root->right = n4;
	n4->left = n5;
	n4->right = n6;

	return root;
}




///////////////////////////////////
void TestBinTree()
{
	TreeNode* root = CreateBinTree();

	printf("前序遍历的结果为:>\n");
	PreOrder(root);
	printf("\n");

	printf("中序遍历的结果为:>\n");
	InOrder(root);
	printf("\n");

	printf("后序遍历的结果为:>\n");
	PostOrder(root);
	printf("\n");
}