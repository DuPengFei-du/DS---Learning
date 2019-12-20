#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Node
{
	char val;
	struct Node* left;   //代表左孩子或者左子树
	struct Node* right;  //代表有孩子或者右子树
}Node;


//前序遍历
void preOrderTraversal(Node* root)   //虽然给的是结点，但是传的是结点的根，代表整个子树
{
	if (root == NULL)
	{
		return;
	}
	//如果这一颗树不为空的话，那么我们先打印根节点
	printf("%c ", root->val);

	//根节点的左子树进行前序遍历
	preOrderTraversal(root -> left);

	//根节点的右子树进行前序遍历
	preOrderTraversal(root->right);
}


//中序遍历
void inOrderTraversal(Node* root)
{
	//如果树是空的，那么直接返回空
	if (root == NULL)
		return;
	//如果树是非空的，那么就实现对左子树进行中序遍历
	//然后打印根节点的值
	//然后在对右子树进行中序遍历

	inOrderTraversal(root->left);

	printf("%c ", root->val);

	inOrderTraversal(root->right);
}


//后序遍历
void postOrderTraversal(Node* root)
{
	//如果树是空的，那么直接返回空
	if (root == NULL)
		return;
	//如果树是非空的，那么就实现对左子树进行后序遍历
	//然后打印根节点的值
	//然后在对右子树进行后序遍历

	postOrderTraversal(root->left);

	postOrderTraversal(root->right);

	printf("%c ", root->val);
}

Node* createNode(char ch)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = ch;
	node->left = node->right = NULL;
	return node;
}


//求二叉树中节点的个数
//我们可以采用遍历的方法求二叉树中结点的个数
//至于用什么方法去便利，可以用前中后序任意一种遍历的方法去遍历
//直接遍历的方法
int count = 0;
void GetNodeCount(Node* root)
{
	if (root == NULL)
	{
		return;
	}

	//count++的位置在最前面的话，就是利用前序遍历，在中间的话，就是利用中序遍历
	//如果在最后面的话，就是利用后序遍历.
	count++;
	GetNodeCount(root->left);
	GetNodeCount(root->right);
}

//转换为求解子问题
int GetNodeCount2(Node* root)
{
	if (root == NULL)
		return 0;

	int left = GetNodeCount2(root->left);
	int right = GetNodeCount2(root->right);

	return left + 1 + right;
}

//求二叉树的高度
int MAX(int a, int b)
{
	return a >= b ? a : b;
}
int getHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = getHeight(root->left);
	int right = getHeight(root->right);

	return MAX(left, right) + 1;
}


//求二叉树中叶子结点的个数
int getLeafCount(Node* root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return getLeafCount(root->left) + getLeafCount(root->right);
}


//求第k层结点的个数
int getKLevelCount(Node* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 1;
	else if (k == 1)
		return 1;
	else
		return getKLevelCount(root->left, k - 1) + getKLevelCount(root->right,k-1);
}


// 查找
Node* find(Node* root, char v)
{
	if (root == NULL)
		return NULL;   //表示没有找到
	if (root->val = v)
		return root;
	//先用一个结点记录下来找到的结点
	//左子树
	Node* left = find(root->left, v);
	if (left != NULL)
		return left;
	//右子树也是同样的道理
	Node* right = find(root->right, v);
	if (right != NULL)
		return right;
	else
		return NULL;
}

//层序遍历
#include<queue>
void levelOrderTraversal(Node* root)
{
	if (root == NULL)
		return;
	std::queue<Node*>q;
	q.push(root);
	while (!q.empty())
	{
		Node* front = q.front();
		q.pop();
		printf("%c", front->val);
		if (front->left != NULL)
			q.push(front->left);
		if (front->right != NULL)
			q.push(front->right);
	}
}

//判断一颗二叉树是否是完全二叉树
bool isCompleteTree(Node* root)
{
	//空树也是完全二叉树
	if (root == NULL)
		return true;
	std::queue<Node*>q;
	q.push(root);
	while (true)   //循环条件其实不重要，因为一定会遇到一个空结点
	{
		Node* front = q.front();
		q.pop();
		if (front == NULL)
		{
			break;
		}
		q.push(front->left);
		q.push(front->right);
	}
	while (!q.empty())
	{
		Node* front = q.front();
		q.pop();
		if (front != NULL)
			return false;
	}
	return true;
}

typedef struct ReturnType
{
	Node* root;
	int used;   //已经用了多少个值了
}ReturnType;
//利用带空结点的前序遍历构建二叉树
//ABDF####C#E#G#
//CreateTree函数需要返回两个值
//1.Node *root;
//2.int ---使用了多少个量
ReturnType createTree(char preorder[], int size)
{
	char rootValue = preorder[0];
	if (rootValue == '#')
	{
		ReturnType returnValue;
		returnValue.root = NULL;
		returnValue.used = 1;
		return returnValue;
	}
	Node* root = (Node*)malloc(sizeof(Node));
	root->val = rootValue;

	ReturnType left = createTree(preorder + 1, size - 1);
	//left.root   创建好的左子树根节点
	//left.used   创建左子树过程中使用掉的值的个数
	ReturnType right = createTree(preorder + 1 + left.used, size - 1 - left.used);
	root->left = left.root;
	root->right = right.root;

	ReturnType returnValue;
	returnValue.root = root;
	returnValue.used = 1 + left.used + right.used;

	return returnValue;
}

void test()
{
	Node* a = createNode('A');
	Node* b = createNode('B');
	Node* c = createNode('C');
	Node* d = createNode('D');
	Node* e = createNode('E');
	Node* f = createNode('F');
	Node* g = createNode('G');
	Node* h = createNode('H');

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	e->right = h;

	//a为根节点，开始遍历
	preOrderTraversal(a);
	printf("\n");

	inOrderTraversal(a);
	printf("\n");

	postOrderTraversal(a);
	printf("\n");

	count = 0;
	GetNodeCount(a);
	printf("结点个数:%d\n", count);

	printf("结点个数2:%d\n", GetNodeCount2(a));

	//求高度
	printf("高度:%d\n", getHeight(a));

	//求叶子结点的个数
	printf("叶子结点个数:%d\n", getLeafCount(a));

	//求第k层结点的个数
	printf("第三层结点的个数：%d\n", getKLevelCount(a, 3));

	//层序遍历
	printf("层序遍历:");
	levelOrderTraversal(a);
	printf("\n");

	//判断一颗二叉树是不是完全二叉树
	if (isCompleteTree(a))
	{
		printf("A是完全二叉树\n");
	}
	else
		printf("A不是完全二叉树\n");
	if (isCompleteTree(c))
	{
		printf("C是完全二叉树\n");
	}
	else
		printf("C不是完全二叉树\n");

}