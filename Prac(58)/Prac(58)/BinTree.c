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
//
//	if (NULL == root)
//		return;
//
//	QueueInit(&q);
//
//	QueuePush(&q,root);
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
//	QueueDestroy(&q);
//}

//�������ٲ���
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

//��ȡ�������н��ĸ���
int GetNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;
}

//��ȡ��������Ҷ�ӽ��ĸ���
int GetLeafNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (NULL == root->left && root->right == NULL)
		return 1;
	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}

//��ȡ��������k����ĸ���
int GetKLevelNodeCount(BTNode* root,int k)
{
	if (root == NULL || k < 0)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}

//�ڶ������н��н��Ĳ���
BTNode* Find(BTNode* root, BTNDataType data)
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->data == data)
		return root;
	(ret = Find(root->left, data)) || (ret = Find(root->right, data));
	return ret;
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

//����һ��������
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





/////////////////////////////
void TestBinTree()
{
	BTNode* root = CreateBinTree();

	printf("ǰ������Ľ��Ϊ:>");
	PreOrder(root);
	printf("\n");

	printf("��������Ľ��Ϊ:>");
	InOrder(root);
	printf("\n");

	printf("��������Ľ��Ϊ:>");
	PostOrder(root);
	printf("\n");

	printf("�������н��ĸ���Ϊ:%d\n", GetNodeCount(root));

	printf("��������Ҷ�ӽ��ĸ���Ϊ:%d\n", GetLeafNodeCount(root));

	printf("��������Ҷ�ӽ��ĸ���Ϊ:%d\n", GetKLevelNodeCount(root,3));

	DestroyTree(&root);
}