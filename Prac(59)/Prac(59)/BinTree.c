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
//	//һ����֮��������Ҫ�ȼ��һ�����ǲ���Ϊ�յ�
//	if (root==NULL)
//	{
//		return;
//	}
//
//	//���յĻ�����ʽ��ʼ����
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
//	//ѭ������֮��˵����������
//	//�ǵ����Ҫ����
//	QueueDestroy(&q);
//}

//��ȡ�������н��ĸ���
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

	//��Ȼ������ʹ�ü������ķ���
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
	if (root == NULL || k == 0)
		return 0;
	if (k == 1)
		return 1;
	//���������ֱ�����������k���н��ĸ�������ô��ʵ�ǲ������
	//�������ǽ���ת��Ϊ���������������
	//��ô��ʵ�������������е�k-1����ĸ���
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}

//�ڶ������н��н��Ĳ���
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

//��ô�����ڣ����������Ҫ��֤һ���⼸�ַ����Ƿ�����ȷ�ģ���ô���ǾͿ�����
//����һ�ֲ���ô����Ĵ���������ʽ�������ȴ�������һ�������Ӷ��Ա����Ľ��������֤�Ĳ���
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
	//��Ҫ����һ�����Ļ�����ô�������������Ҫ���ڵ�
	//Ȼ�������ȥ������
	assert(root);   //root�е�������ʵ�����ⲿʵ�εĵ�ַ
	if (*root)      //*root�����ⲿ��ʵ��
	{
		DestroyTree(&(*root)->left);    //�Ƚ������õ�ֵ��Ȼ����ȡ��ַ���͵õ���ַ��
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
//�������ȼ򵥵Ĺ����֮��Ϳ��Խ���һϵ�еĲ�����

void TestBinTree()
{
	BTNode* root = CreateBinaryTree();
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

	DestroyTree(&root);
}
