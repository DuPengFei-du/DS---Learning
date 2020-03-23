#include"SList.h"


void SListInit(List *pl)
{
	//�ȿ���������Ƿ����
	assert(pl);
	//��ΪҪ��ʼ����������һ��ʼ����������ʵ��ʲô��û�еģ���ô
	pl->head = NULL;
	//��ͷ�ڵ�Ϊ�գ��������ĳ�ʼ��
}

void SListDestroy(List* pl)
{
	Node* pCur = NULL;
	//ȷ���������
	assert(pl);
	//���Ҫȥ�ͷ�����Ļ�����ô��Ҫһ�����һ�����ȥ�ͷ�
	pCur = pl->head;
	while (pCur)
	{
		pl->head = pCur->next;
		free(pCur);
		pCur = pl->head;
		//���һ�������ͷţ�Ȼ��һֱȥѭ���ͷŽ��
	}
	//�������Ѿ�ȫ���ͷ�����ˣ��ǵ���ͷ���Ϊ��
	pl->head = NULL;
}

//��Ҫ���ؽ�㣬���Է���ֵΪNode*
Node* CreatNode(int data)
{
	//�ȴ���һ�����
	Node* node = (Node*)malloc(sizeof(Node));
	if (NULL == node)
	{
		assert(0);
		return NULL;
	}
	//��������ɹ���
	node->data = data;
	node->next = NULL;
	return node;
}

void SListPushBack(List* pl, int data)
{
	Node *pCur=NULL;
	Node* pNewNode = NULL;
	assert(pl);
	//β�������˼·��
	//��Ҫ���������ҵ����һ����㣬Ȼ�������һ�����ĺ������һ��Ԫ�ؾͿ�����
	//����������������һ��ʼʲôԪ�ض�û�еĻ�����ôֱ���ò���Ľ���Ϊͷ���Ϳ�����
	pCur = pl->head;
	pNewNode = CreatNode(data);
	if (pl->head == NULL)
		pl->head = pNewNode;
	else
	{
		while (pCur->next)
		{
			pCur = pCur->next;
		}
		//������Ѿ������һ���ڵ���
		pCur->next = pNewNode;
		pNewNode->next = NULL;
	}
}

void SListPrint(List* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->head;
	while (pCur)
	{
		printf("%d--->", pCur->data);
		pCur = pCur->next;
	}
	printf("NULL\n");
}