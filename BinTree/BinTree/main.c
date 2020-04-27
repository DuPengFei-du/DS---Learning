#include"BinTree.h"

int main()
{
	char* pStr = "ABD###CE##F";  //前序遍历结果
	BTNode* pRoot = CreateBinTree(pStr, strlen(pStr));
	BTNode* pNewRoot = CopyBinTree(pRoot);
	BTNode* pParent;

	printf("前序遍历为:");
	PreOrder(pRoot);
	printf("\n");

	printf("前序遍历为:");
	PreOrder(pNewRoot);   //拷贝完了之后为了验证拷贝的代码是否正确
	printf("\n");

	printf("中序遍历为:");
	InOrder(pRoot);
	printf("\n");

	printf("中序遍历为:");
	InOrder(pNewRoot);
	printf("\n");

	printf("后序遍历为:");
	PostOrder(pRoot);
	printf("\n");

	printf("后序遍历为:");
	PostOrder(pNewRoot);
	printf("\n");

	printf("二叉树中结点的个数:%d\n", GetNodeCount(pRoot));

	printf("二叉树高度:%d\n",Height(pRoot));

	printf("二叉树是否平衡:%d\n", IsBalanceTree(pRoot));

	printf("二叉树中叶子结点的个数为:%d\n", GetLeafNodeCount(pRoot));

	printf("二叉树中第3层结点的个数为:%d\n", GetKLevelNodeCount(pRoot,3));

	pParent = GetNodeParent(pRoot, GetNode(pRoot, 'D'));
	pParent = GetNodeParent(pRoot, GetNode(pRoot, 'G'));


	DestroyBinTree(&pRoot);

	DestroyBinTree(&pNewRoot);

}