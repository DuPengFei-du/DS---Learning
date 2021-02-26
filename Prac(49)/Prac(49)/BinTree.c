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

////�������Ĳ������
//void LevelOrder(BTNode* root)
//{
//	//�������Ĳ��������Ҫ�õ����е����ֽṹ�ſ��� 
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
//	//������֮�󣬼ǵ�Ҫ�Ѷ������ٵ��ſ���
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
//	//����Ҳ����ȫ������
//	if (root == NULL)
//		return 1;
//
//	//����ǿյĻ�����ô���ȰѸ��ڵ�Ž�ȥ
//  QueueInit(&q);
//	QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* cur = QueueFront(&q);
//
//		if (flag)
//		{
//			//�����Ľ�㶼�����к���
//			if (cur->left || cur->right)
//				break;
//		}
//		else   //��ȥ�ҵ�һ�������͵Ľ��
//		{
//			if (cur->left && cur->right)
//			{
//				QueuePush(&q, cur->left);
//				QueuePush(&q, cur->right);
//			}
//			else if (cur->left)
//			{
//				//curֻ�����ӣ���ô�����ٽ���������ҵ���
//				QueuePush(cur->left);
//				flag = 1;
//			}
//			else if (cur->right)
//			{
//				//cur ֻ���Һ���
//				 break;
//			}
//			else
//			{
//				flag = 1;
//			}
//		}
//
//		QueuePop(&q);//��Ԫ���ó���֮����ѭ����������
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

//��������һ�ü����������
BTNode* CreateBinTree()
{
	BTNode* root = NULL;

	//��������������
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

//�������н��ĸ���
int GetNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + GetNodeCount(root->left) + GetNodeCount(root->right);
}

//��������Ҷ�ӽ��ĸ���
int GetLeafNodeCount(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}

//�������е�k����ĸ���
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

	printf("ǰ������Ľ��Ϊ��\n");
	PreOrder(root);
	printf("\n");

	printf("��������Ľ��Ϊ��\n");
	InOrder(root);
	printf("\n");

	printf("��������Ľ��Ϊ��\n");
	PostOrder(root);
	printf("\n");

	printf("�������н��ĸ���Ϊ: %d \n", GetNodeCount(root));

	printf("�������н��ĸ���Ϊ: %d \n", GetLeafNodeCount(root));

	BTNode* ret = TreeFind(root, 3);
	if (ret)
		printf("3 is in the tree\n");
	else 
		printf("3 is not in the tree\n");

	printf("�������ĸ߶�Ϊ: %d \n", GetHeight(root));

	DestroyTree(&root);
}