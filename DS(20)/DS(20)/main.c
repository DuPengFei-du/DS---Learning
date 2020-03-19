#include"List.h"

void ListInit(List* s)
{
	assert(s);
	s->head = NULL;   //��Ϊһ����㶼û�У���ô�Ͱ�ͷ�óɿ�
}

Node *CreatNode(int data)  //��ΪҪ���ؽ�㣬���Է���ֵΪNode*
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	if (NULL == pNode)
	{
		assert(0);
		return NULL;
	}
	pNode->data = data;
	pNode->next = NULL;
	return pNode;
}

void ListPushBack(List* s, int data)
{
	//β���˼·��
	//�����ҵ����һ����㣬�����һ������next���Ϊ�µĽ��
	Node* pNewNode = NULL;
	Node* pCur = NULL;
	assert(s);
	pNewNode = CreatNode(data);
	pCur = s->head;
	if (s->head == NULL)
	{
		s->head = pNewNode;
	}
	else
	{
		while (pCur->next)
		{
			pCur = pCur->next;
		}
		pCur->next = pNewNode;
	}
}

void ListPrint(List* s)
{
	Node* pCur = NULL;
	assert(s);
	pCur = s->head;
	while (pCur)
	{
		printf("%d--->", pCur->data);
		pCur = pCur->next;
	}
	printf("NULL\n");
}