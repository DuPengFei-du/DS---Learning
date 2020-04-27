#include"BinTree.h"

int main()
{
	char* pStr = "ABD###CE##F";  //ǰ��������
	BTNode* pRoot = CreateBinTree(pStr, strlen(pStr));
	BTNode* pNewRoot = CopyBinTree(pRoot);
	BTNode* pParent;

	printf("ǰ�����Ϊ:");
	PreOrder(pRoot);
	printf("\n");

	printf("ǰ�����Ϊ:");
	PreOrder(pNewRoot);   //��������֮��Ϊ����֤�����Ĵ����Ƿ���ȷ
	printf("\n");

	printf("�������Ϊ:");
	InOrder(pRoot);
	printf("\n");

	printf("�������Ϊ:");
	InOrder(pNewRoot);
	printf("\n");

	printf("�������Ϊ:");
	PostOrder(pRoot);
	printf("\n");

	printf("�������Ϊ:");
	PostOrder(pNewRoot);
	printf("\n");

	printf("�������н��ĸ���:%d\n", GetNodeCount(pRoot));

	printf("�������߶�:%d\n",Height(pRoot));

	printf("�������Ƿ�ƽ��:%d\n", IsBalanceTree(pRoot));

	printf("��������Ҷ�ӽ��ĸ���Ϊ:%d\n", GetLeafNodeCount(pRoot));

	printf("�������е�3����ĸ���Ϊ:%d\n", GetKLevelNodeCount(pRoot,3));

	pParent = GetNodeParent(pRoot, GetNode(pRoot, 'D'));
	pParent = GetNodeParent(pRoot, GetNode(pRoot, 'G'));


	DestroyBinTree(&pRoot);

	DestroyBinTree(&pNewRoot);

}