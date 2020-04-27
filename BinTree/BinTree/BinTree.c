#include"BinTree.h"


//ǰ�����򣬺���ı������� ѭ����ʱ�临�Ӷȶ�ΪO(N)

//ǰ������Ĺ���:
//���ڵ�---������---������
void PreOrder(BTNode* pRoot)
{
	//���ڶ�������˵��Ҳ��Ҫ�пյĲ���
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
//		//�Һ���
//		if (pCur->_pRight)
//			StackPush(&s, pCur->_pRight);
//		//����
//		if (pCur->_pLeft)
//			StackPush(&s, pCur->_pLeft);
//	}
//	StackDestroy(&s);
//	printf("\n");
//}

//������---���ڵ�---������
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
//	//����pCurΪ���Ķ�����������㣬������������·���е����н��
//	while (pCur||StackEmpty(&s))
//	{
//		while (pCur)
//		{
//			StackPush(&s, pCur);  //������
//			pCur = pCur->_pLeft;
//		}
//		//��ȡջ��
//		pCur = StackTop(&s);
//		printf("%c", pCur->data);
//		StackPop(&s);
//		pCur = pCur->_pRight;
//	}
//}

//������---������---��
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
//	BTNode* prev = NULL;    //�������շ��ʹ��Ľ��
//	Stack s;
//	StackInit(&s);
//	//����pCurΪ���Ķ����������Ľ�㣬��������������·�������н��
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
//	//���������Ҫ�õ�����
//	Queue q;
//	if (NULL == pRoot)
//		return;
//	QueueInit(&q);   //��ʼ������
//	QueuePush(&q, pRoot);
//	while (!QueueEmpty(&q))
//	{
//		//�Ӷ�����ȡ��Ԫ��
//		BTNode* pCur = QueueFront(&q);
//		printf("%c", pCur->data);
//		//��⵱ǰ����Ƿ��������
//		if (pCur->_pLeft)
//			QueuePush(&q, pCur->_pLeft);
//		//��⵱ǰ����Ƿ�����Һ���
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
		return 1;   //����Ҳ��ƽ����
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
		return 1;   //����Ҳ��ƽ����
	//��֤pRoot�����������Ƿ�ƽ��
	IsLBalance = IsBalanceTreeII(pRoot->_pLeft, &leftHeight);
	IsRBalance = IsBalanceTreeII(pRoot->_pRight, &rightHeight);
	if (IsLBalance && IsRBalance && abs(rightHeight - leftHeight) < 2)
	{
		*height= leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		return 1;
	}
	return 0;
}

//�������
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
	//���ٶ�������ʱ�򣬲��������ٸ��ڵ�
	//��������ٸ��ڵ�Ļ������Ҳ�������������
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
		//�������ڵ�
		pNewRoot = BuyBinTreeNode(pRoot->data);
		//�������ڵ��������
		if(pRoot->_pLeft)  //���յĻ���ȥ����������������Ӱ��ĵݹ����
			pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);
		//�������ڵ��������
		if (pRoot->_pRight)
			pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return pNewRoot;
}

int GetLeafNodeCount(BTNode* pRoot)
{
	//������û��Ҷ�ӽڵ��
	if (NULL == pRoot)
		return 0;
	//ֻ��һ����㣬��ôҶ�ӽ�����ֻ��һ����Ϊ�����
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
	//ȥ���������м����k-1����ĸ���
	return GetKLevelNodeCount(pRoot->_pLeft, k - 1) + GetKLevelNodeCount(pRoot->_pRight, k - 1);
	//������ĸ߶�С��k�����յ�����˵����k��Ľ������϶���0��
	//���ǲ���ȥ���⴦��ͨ�������ĵݹ����Ҳ����ɵ�k������������
	//����k�������ĸ߶ȣ���Ȼ����
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