#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Node
{
	char val;
	struct Node* left;   //�������ӻ���������
	struct Node* right;  //�����к��ӻ���������
}Node;


//ǰ�����
void preOrderTraversal(Node* root)   //��Ȼ�����ǽ�㣬���Ǵ����ǽ��ĸ���������������
{
	if (root == NULL)
	{
		return;
	}
	//�����һ������Ϊ�յĻ�����ô�����ȴ�ӡ���ڵ�
	printf("%c ", root->val);

	//���ڵ������������ǰ�����
	preOrderTraversal(root -> left);

	//���ڵ������������ǰ�����
	preOrderTraversal(root->right);
}


//�������
void inOrderTraversal(Node* root)
{
	//������ǿյģ���ôֱ�ӷ��ؿ�
	if (root == NULL)
		return;
	//������Ƿǿյģ���ô��ʵ�ֶ������������������
	//Ȼ���ӡ���ڵ��ֵ
	//Ȼ���ڶ������������������

	inOrderTraversal(root->left);

	printf("%c ", root->val);

	inOrderTraversal(root->right);
}


//�������
void postOrderTraversal(Node* root)
{
	//������ǿյģ���ôֱ�ӷ��ؿ�
	if (root == NULL)
		return;
	//������Ƿǿյģ���ô��ʵ�ֶ����������к������
	//Ȼ���ӡ���ڵ��ֵ
	//Ȼ���ڶ����������к������

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


//��������нڵ�ĸ���
//���ǿ��Բ��ñ����ķ�����������н��ĸ���
//������ʲô����ȥ������������ǰ�к�������һ�ֱ����ķ���ȥ����
//ֱ�ӱ����ķ���
int count = 0;
void GetNodeCount(Node* root)
{
	if (root == NULL)
	{
		return;
	}

	//count++��λ������ǰ��Ļ�����������ǰ����������м�Ļ������������������
	//����������Ļ����������ú������.
	count++;
	GetNodeCount(root->left);
	GetNodeCount(root->right);
}

//ת��Ϊ���������
int GetNodeCount2(Node* root)
{
	if (root == NULL)
		return 0;

	int left = GetNodeCount2(root->left);
	int right = GetNodeCount2(root->right);

	return left + 1 + right;
}

//��������ĸ߶�
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


//���������Ҷ�ӽ��ĸ���
int getLeafCount(Node* root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return getLeafCount(root->left) + getLeafCount(root->right);
}


//���k����ĸ���
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


// ����
Node* find(Node* root, char v)
{
	if (root == NULL)
		return NULL;   //��ʾû���ҵ�
	if (root->val = v)
		return root;
	//����һ������¼�����ҵ��Ľ��
	//������
	Node* left = find(root->left, v);
	if (left != NULL)
		return left;
	//������Ҳ��ͬ���ĵ���
	Node* right = find(root->right, v);
	if (right != NULL)
		return right;
	else
		return NULL;
}

//�������
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

//�ж�һ�Ŷ������Ƿ�����ȫ������
bool isCompleteTree(Node* root)
{
	//����Ҳ����ȫ������
	if (root == NULL)
		return true;
	std::queue<Node*>q;
	q.push(root);
	while (true)   //ѭ��������ʵ����Ҫ����Ϊһ��������һ���ս��
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
	int used;   //�Ѿ����˶��ٸ�ֵ��
}ReturnType;
//���ô��ս���ǰ���������������
//ABDF####C#E#G#
//CreateTree������Ҫ��������ֵ
//1.Node *root;
//2.int ---ʹ���˶��ٸ���
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
	//left.root   �����õ����������ڵ�
	//left.used   ����������������ʹ�õ���ֵ�ĸ���
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

	//aΪ���ڵ㣬��ʼ����
	preOrderTraversal(a);
	printf("\n");

	inOrderTraversal(a);
	printf("\n");

	postOrderTraversal(a);
	printf("\n");

	count = 0;
	GetNodeCount(a);
	printf("������:%d\n", count);

	printf("������2:%d\n", GetNodeCount2(a));

	//��߶�
	printf("�߶�:%d\n", getHeight(a));

	//��Ҷ�ӽ��ĸ���
	printf("Ҷ�ӽ�����:%d\n", getLeafCount(a));

	//���k����ĸ���
	printf("��������ĸ�����%d\n", getKLevelCount(a, 3));

	//�������
	printf("�������:");
	levelOrderTraversal(a);
	printf("\n");

	//�ж�һ�Ŷ������ǲ�����ȫ������
	if (isCompleteTree(a))
	{
		printf("A����ȫ������\n");
	}
	else
		printf("A������ȫ������\n");
	if (isCompleteTree(c))
	{
		printf("C����ȫ������\n");
	}
	else
		printf("C������ȫ������\n");

}