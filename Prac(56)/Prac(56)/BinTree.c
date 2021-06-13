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
//	//���������Ҫ���������е����ֽṹ
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
//	//�����˶��еĽṹ֮�󣬼ǵ������������
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

//���ڸ���һ�ּ���Ĵ������ķ�ʽ����ôΪʲô�Ǽ���Ĵ������ķ�ʽ��
//��Ϊ���ַ�ʽֻ��ͨ�����ٽ��Ŀռ䣬�������һ������ϣ��ȥ������
//������״���������ǰ����ִ������ķ�ʽ��Ϊ����Ĵ�������һ�ַ�ʽ
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

	printf("ǰ������Ľ��Ϊ:>\n");
	PreOrder(root);
	printf("\n");

	printf("��������Ľ��Ϊ:>\n");
	InOrder(root);
	printf("\n");

	printf("��������Ľ��Ϊ:>\n");
	PostOrder(root);
	printf("\n");
}