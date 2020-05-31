#include"BinTree.h"

//前序遍历
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d", root->val);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d", root->val);
		InOrder(root->right);
	}
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d", root->val);
	}
}

//求二叉树中结点的个数
//思路就是，可以依据前序，中序，后序的思路
//遍历的方法是遇到一个结点就把哪个结点打印出来
//在这里，可以看成是遇到一个结点就给计数加一，从而可以算出来二叉树中结点的个数
int count = 0;   //用作计数
int GetNodeCount(BTNode* root)
{
	if (root)
	{
		count++;
		GetNodeCount(root->left);   //按照同样的方式去统计二叉树中左子树中的结点
		GetNodeCount(root->right);  //按照同样的方式去统计二叉树中右子树中的结点
	}
	return count;
}
/*
不能使用count计数器的方式
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
	//不能按照这样的方式来返回，因为如果按照这样的方式来返回的话
	//就返回的是真或者假的结果了
	//return GetParent(root->left, pNode) || GetParent(root->right, pNode);
	return NULL;
}


//创建二叉树，但是不是真正意义上的创建二叉树的方式
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

//创建结点
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

	printf("前序遍历结果为：");
	PreOrder(root);
	printf("\n");

	printf("中序遍历结果为：");
	InOrder(root);
	printf("\n");

	printf("后序遍历结果为：");
	PostOrder(root);
	printf("\n");

	//获取二叉树中结点的个数
	printf("二叉树中结点个数为:%d\n", GetNodeCount(root));

	printf("二叉树中结点个数为:%d\n", GetNodeCountII(root));

	//叶子结点的个数
	printf("二叉树中叶子结点个数为:%d\n", GetLeafCount(root));

	//高度
	printf("二叉树高度为:%d\n", GetHeight(root));

	//第k层的个数
	printf("二叉树第3层的个数为:%d\n", GetKLevelCount(root,3));


	BTNode* pNode = Find(root, 3);

	BTNode* pParent = GetParent(root, Find(root,3));
	if (pParent)
	{
		printf("3的parent is %d!!!\n", pParent->val);
	}
	else
	{
		printf("3 has no parent ");
	}

}