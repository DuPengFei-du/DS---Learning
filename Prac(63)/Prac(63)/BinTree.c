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

////���������Ҫ�õ����еĽṹ
//void LevelOrder(BTNode* root)
//{
//	//���������Ҫ���������������ݽṹ
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
//	//��������ˣ��ǵðѶ������ٵ�
//	QueueDestroy(&q);
//}

//��ȡ�������н��ĸ���
int GetNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + GetNodeCount(root->left) + GetNodeCount(root->right);
}

//��ȡ��������Ҷ�ӽ��ĸ���
int GetLeafNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}

//��ȡ��������k����ĸ���
int GetKLevelNodeCount(BTNode* root, unsigned int k)
{
	if (root == NULL || k < 0)
		return 0;
	if (k == 1)
		return 1;
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}

//��ȡ�������ĸ߶�
int GetHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

////�ж�һ�����Ƿ�����ȫ������
//int BinaryTreeComplete(BTNode* root)
//{
//	//��Ҫ�����������������ݽṹ
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

//�ڶ������н��н��Ĳ���
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

//�������н��Ĵ���
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

//�����������ٲ���
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

//�������Ŀ�������
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

//�������Ĵ���
BTNode* CreateBinaryTree(int array[], int size, int* index, int invalid)
{
	BTNode* root = NULL;

	if (*index < size && invalid != array[*index])
	{
		root = CreateNode(array[*index]);

		//Ȼ��ȥ�������ڵ��������
		++(*index);
		root->left = CreateBinaryTree(array, size, index, invalid);

		//Ȼ��ȥ�������ڵ��������
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

	printf("ǰ��������Ϊ:\n");
	PreOrder(root);
	printf("\n");

	printf("����������Ϊ:\n");
	InOrder(root);
	printf("\n");

	printf("����������Ϊ:\n");
	PostOrder(root);
	printf("\n");

	printf("���н��ĸ���Ϊ:%d\n", GetNodeCount(root));

	printf("����Ҷ�ӽ��ĸ���Ϊ:%d\n", GetLeafNodeCount(root));

	printf("���е�k����ĸ���Ϊ:%d\n", GetKLevelNodeCount(root, 3));

	BTNode* cur = Find(root, 4);
	if (cur != NULL)
	{
		printf("4 is in the tree\n");
	}
	else
	{
		printf("4 is not in the tree\n");
	}

	printf("���ĸ߶�Ϊ:%d\n", GetHeight(root));

	//��root����������µ���

	NewRoot = CopyBinTree(root);

	printf("ǰ��������Ϊ:\n");
	PreOrder(root);
	printf("\n");

	printf("����������Ϊ:\n");
	InOrder(root);
	printf("\n");

	printf("����������Ϊ:\n");
	PostOrder(root);
	printf("\n");

	DestroyTree(&root);

	DestroyTree(&NewRoot);

}