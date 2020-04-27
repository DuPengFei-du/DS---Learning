#include"BinTree.h"


//前序，中序，后序的遍历过程 循环的时间复杂度都为O(N)

//前序遍历的过程:
//根节点---左子树---右子树
void PreOrder(BTNode* pRoot)
{
	//对于二叉树来说，也需要判空的操作
	if (pRoot == NULL)
		return;
	printf("%c ", pRoot->data);
	PreOrder(pRoot->_pLeft);
	PreOrder(pRoot->_pRight);
}

//void PreOrderNor(BTNode* pRoot)
//{
//	Stack s;
//	if (NULL == pRoot)
//		return;
//	StackInit(&s);
//	while (!StackEmpty(&s))
//	{
//		BTNode* pCur = StackTop(&s);
//		StackPop(&s);
//		printf("%c", pCur->data);
//		//右孩子
//		if (pCur->_pRight)
//			StackPush(&s, pCur->_pRight);
//		//左孩子
//		if (pCur->_pLeft)
//			StackPush(&s, pCur->_pLeft);
//	}
//	StackDestroy(&s);
//	printf("\n");
//}

//左子树---根节点---右子树
void InOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
	InOrder(pRoot->_pLeft);
	printf("%c ", pRoot->data);
	InOrder(pRoot->_pRight);
}

//void InOrderNor(BTNode* pRoot)
//{
//	Stack s;
//	BTNode* pCur = pRoot;
//	StackInit(&s);
//	//找以pCur为根的二叉树最左侧结点，并保存所经过路径中的所有结点
//	while (pCur||StackEmpty(&s))
//	{
//		while (pCur)
//		{
//			StackPush(&s, pCur);  //保存结点
//			pCur = pCur->_pLeft;
//		}
//		//获取栈顶
//		pCur = StackTop(&s);
//		printf("%c", pCur->data);
//		StackPop(&s);
//		pCur = pCur->_pRight;
//	}
//}

//左子树---右子树---根
void PostOrder(BTNode* pRoot)
{
	if (pRoot == NULL)
		return;
	PostOrder(pRoot->_pLeft);
	PostOrder(pRoot->_pRight);
	printf("%c ", pRoot->data);
}

//void PostOrderNor(BTNode* pRoot)
//{
//	BTNode* pCur = pRoot;
//	BTNode* prev = NULL;    //标记最近刚访问过的结点
//	Stack s;
//	StackInit(&s);
//	//找以pCur为根的二叉树最左侧的结点，并保存其所经过路径的所有结点
//	while (pCur || !StackEmpty(&s))
//	{
//		while (pCur)
//		{
//			StackPush(&s, pCur);
//			pCur = pCur->_pLeft;
//		}
//		BTNode* pTop = StackTop(&s);
//		if (NULL == pTop->_pRight||pTop->_pRight==prev)
//		{
//			printf("%c ", pTop->data);
//			StackPop(&s);
//			prev = pTop;
//		}
//		else
//		{
//			pCur = pTop->_pRight;
//		}
//	}
//	printf("\n");
//	StackDestroy(&s);
//}

//void LevelOrder(BTNode* pRoot)
//{
//	//层序遍历需要用到队列
//	Queue q;
//	if (NULL == pRoot)
//		return;
//	QueueInit(&q);   //初始化队列
//	QueuePush(&q, pRoot);
//	while (!QueueEmpty(&q))
//	{
//		//从队列中取出元素
//		BTNode* pCur = QueueFront(&q);
//		printf("%c", pCur->data);
//		//检测当前结点是否存在左孩子
//		if (pCur->_pLeft)
//			QueuePush(&q, pCur->_pLeft);
//		//检测当前结点是否存在右孩子
//		if (pCur->_pRight)
//			QueuePush(&q, pCur->_pRight);
//		QueuPop(&q);
//	}
//	printf("\n");
//}

int GetNodeCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	return GetNodeCount(pRoot->_pLeft) + GetNodeCount(pRoot->_pRight) + 1;
}

int Height(BTNode* pRoot)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (NULL == pRoot)
		return 0;
	leftHeight = Height(pRoot->_pLeft);
	rightHeight = Height(pRoot->_pRight);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

}

int IsBalanceTree(BTNode* pRoot)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if(NULL == pRoot)
		return 1;   //空树也是平衡树
	leftHeight = Height(pRoot->_pLeft);
	rightHeight = Height(pRoot->_pRight);
	return abs(rightHeight - leftHeight) < 2 && IsBalanceTree(pRoot->_pLeft) && IsBalanceTree(pRoot->_pRight);
}

int IsBalanceTreeII(BTNode* pRoot, int* height)
{
	int IsLBalance = 0;
	int IsRBalance = 0;
	int leftHeight = 0;
	int rightHeight = 0;
	if (NULL == pRoot)
		return 1;   //空树也是平衡树
	//验证pRoot的左右子树是否平衡
	IsLBalance = IsBalanceTreeII(pRoot->_pLeft, &leftHeight);
	IsRBalance = IsBalanceTreeII(pRoot->_pRight, &rightHeight);
	if (IsLBalance && IsRBalance && abs(rightHeight - leftHeight) < 2)
	{
		*height= leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		return 1;
	}
	return 0;
}

//创建结点
BTNode* BuyBinTreeNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
		assert(0);
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	pNewNode->data = data;
	return pNewNode;

}

BTNode* _CreateBinTree(BTDataType* array, int size,int *index)
{
	BTNode* pRoot = NULL;
	if (*index < size&&'#'!=array[*index])
	{
		pRoot = BuyBinTreeNode(array[*index]);
		(*index)++;
		pRoot->_pLeft = _CreateBinTree(array,size, index);
		(*index)++;
		pRoot->_pRight = _CreateBinTree(array,size, index);
	}
	return pRoot;
}

BTNode* CreateBinTree(BTDataType* array, int size)
{
	int index = 0;
	return _CreateBinTree(array, size, &index);
}

void DestroyBinTree(BTNode** pRoot)
{
	assert(pRoot);
	//销毁二叉树的时候，不能先销毁根节点
	//如果先销毁根节点的话，就找不到左右子树了
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		pRoot = NULL;
	}
}

BTNode* CopyBinTree(BTNode* pRoot)
{
	BTNode* pNewRoot = NULL;
	if (pRoot)
	{
		//拷贝根节点
		pNewRoot = BuyBinTreeNode(pRoot->data);
		//拷贝根节点的左子树
		if(pRoot->_pLeft)  //不空的话再去拷贝，以免增加无影响的递归次数
			pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);
		//拷贝根节点的右子树
		if (pRoot->_pRight)
			pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return pNewRoot;
}

int GetLeafNodeCount(BTNode* pRoot)
{
	//空树是没有叶子节点的
	if (NULL == pRoot)
		return 0;
	//只有一个结点，那么叶子结点就是只有一个，为根结点
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;
	return GetLeafNodeCount(pRoot->_pLeft) + GetLeafNodeCount(pRoot->_pRight);
}

int GetKLevelNodeCount(BTNode* pRoot, int k)
{
	if(NULL == pRoot || k < 1)
		return 0;
	if (1 == k)
		return 1;
	//去左右子树中计算第k-1层结点的个数
	return GetKLevelNodeCount(pRoot->_pLeft, k - 1) + GetKLevelNodeCount(pRoot->_pRight, k - 1);
	//如果树的高度小于k，按照道理来说，第k层的结点个数肯定是0个
	//但是不用去特殊处理，通过上述的递归代码也能完成第k层结点个数的求解
	//尽管k大于树的高度，仍然成立
}

BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode)
{
	BTNode* pParent = NULL;
	if (NULL == pRoot || NULL == pNode)
	{
		return NULL;
	}
	if (pRoot == pNode)
	{
		return NULL;
	}
	if (pRoot->_pLeft == pNode || pRoot->_pRight == pNode)
	{
		return pRoot;
	}
	pParent = GetNodeParent(pRoot->_pLeft, pNode);
	if (pParent)
		return pParent;
	return GetNodeParent(pRoot->_pRight, pNode);
}

BTNode* GetNode(BTNode* pRoot, BTDataType data)
{
	BTNode* pNode = NULL;
	if (NULL == pRoot)
	{
		return NULL;
	}
	if (pRoot->data == data)
		return pRoot;
	if (pNode == GetNode(pRoot->_pLeft, data))
		return pNode;
	return GetNode(pRoot->_pRight, data);
}

void Mirror(BTNode* pRoot)
{
	if (pRoot)
	{
		Swap(&(pRoot->_pLeft), &(pRoot->_pRight));
		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}
void Swap(BTNode** pLeft, BTNode** pRight)
{
	BTNode* pTemp = *pLeft;
	*pLeft = *pRight;
	*pRight = pTemp;
}

void MirrorNor(BTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q,pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		Swap(&(pCur->_pLeft), &(pCur->_pRight));
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);
		QueuePop(&q);
	}
}