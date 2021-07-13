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
//	Queue q;
//	//层序遍历，需要借助到队列的这种数据结构
//	if (root == NULL)
//		return;
//
//	QueueInit(&q);
//
//	QueuePush(&q, root);
//
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
//
//	//用完之后，记得销毁这种数据结构
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


BTNode* CreateNode(BTNDataType data)
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

BTNode* CreateBinTree()
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





/////////////////////////
void TestBinTree()
{
	BTNode* root = CreateBinTree();
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
}