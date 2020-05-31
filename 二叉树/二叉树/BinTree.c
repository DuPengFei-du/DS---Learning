#include"BinTree.h"

//ǰ�����
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d", root->val);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//�������
void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d", root->val);
		InOrder(root->right);
	}
}

//�������
void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d", root->val);
	}
}

//��������н��ĸ���
//˼·���ǣ���������ǰ�����򣬺����˼·
//�����ķ���������һ�����Ͱ��ĸ�����ӡ����
//��������Կ���������һ�����͸�������һ���Ӷ�����������������н��ĸ���
int count = 0;   //��������
int GetNodeCount(BTNode* root)
{
	if (root)
	{
		count++;
		GetNodeCount(root->left);   //����ͬ���ķ�ʽȥͳ�ƶ��������������еĽ��
		GetNodeCount(root->right);  //����ͬ���ķ�ʽȥͳ�ƶ��������������еĽ��
	}
	return count;
}
/*
����ʹ��count�������ķ�ʽ
*/

int GetNodeCountII(BTNode* root)
{
	if (NULL == root)
	{
		return 0;
	}
	else
		return 1 + GetNodeCountII(root->left) + GetNodeCountII(root->right);
}

int GetLeafCount(BTNode* root)
{
	if (NULL == root)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return GetLeafCount(root->left) + GetLeafCount(root->right);
}

int GetHeight(BTNode* root)
{
	int leftHeight = GetLeafCount(root->left);
	int rightHeight = GetLeafCount(root->right);
	if (NULL == root)
		return 0;
	else
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int GetKLevelCount(BTNode* root,int k)
{
	if (NULL == root || k <= 0)
		return 0;
	else if (k == 1)
		return 1;
	else
		return GetKLevelCount(root->left, k - 1) + GetKLevelCount(root->right, k - 1);
}

BTNode* Find(BTNode* root, BTDataType x)
{
	if (NULL == root)
		return NULL;
	if (root->val == x)
		return root;
	BTNode* pNode = NULL;
	if ((pNode = Find(root->left, x)) || (pNode = Find(root->right, x)))
		return pNode;
	return NULL;
}

BTNode* GetParent(BTNode* root, BTNode* pNode)
{
	BTNode* pParent = NULL;
	if (NULL == root)
		return NULL;
	if (pNode == root->left || pNode == root->right)
		return root;
	if((pParent= GetParent(root->left, pNode))|| (pParent = GetParent(root->right, pNode)))
		return pParent;
	//���ܰ��������ķ�ʽ�����أ���Ϊ������������ķ�ʽ�����صĻ�
	//�ͷ��ص�������߼ٵĽ����
	//return GetParent(root->left, pNode) || GetParent(root->right, pNode);
	return NULL;
}


//���������������ǲ������������ϵĴ����������ķ�ʽ
BTNode* CreateBinTree()
{
	BTNode* node1 = BuyBinTreeNode(1);
	BTNode* node2 = BuyBinTreeNode(2);
	BTNode* node3 = BuyBinTreeNode(3);
	BTNode* node4 = BuyBinTreeNode(4);
	BTNode* node5 = BuyBinTreeNode(5);
	BTNode* node6 = BuyBinTreeNode(6);

	BTNode* root = node1;
	node1->left = node2;
	node2->left = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;
	return root;
}

//�������
BTNode* BuyBinTreeNode(BTDataType val)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->left = NULL;
	pNewNode->right = NULL;
	pNewNode->val = val;
	return pNewNode;
}

void TestBinTree()
{
	BTNode* root = CreateBinTree();

	printf("ǰ��������Ϊ��");
	PreOrder(root);
	printf("\n");

	printf("����������Ϊ��");
	InOrder(root);
	printf("\n");

	printf("����������Ϊ��");
	PostOrder(root);
	printf("\n");

	//��ȡ�������н��ĸ���
	printf("�������н�����Ϊ:%d\n", GetNodeCount(root));

	printf("�������н�����Ϊ:%d\n", GetNodeCountII(root));

	//Ҷ�ӽ��ĸ���
	printf("��������Ҷ�ӽ�����Ϊ:%d\n", GetLeafCount(root));

	//�߶�
	printf("�������߶�Ϊ:%d\n", GetHeight(root));

	//��k��ĸ���
	printf("��������3��ĸ���Ϊ:%d\n", GetKLevelCount(root,3));


	BTNode* pNode = Find(root, 3);

	BTNode* pParent = GetParent(root, Find(root,3));
	if (pParent)
	{
		printf("3��parent is %d!!!\n", pParent->val);
	}
	else
	{
		printf("3 has no parent ");
	}

}