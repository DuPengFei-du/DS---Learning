#include"LinkedList.h"

//ʱ�临��Ϊ(1)
Node *ListPushFront(Node* head,int val)
{
	//val ���ڽ���У���װ������
	//�൱���Ǵ���һ���µĽ��
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = val;
	//��node����һ�����ָ��ԭ������ĵ�һ���ڵ�
	node->next = head;
	//��node ��Ϊ�µĵ�һ�����
	head = node;
	return node;
}
void  ListPrint(Node* head)
{
	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->data);
	}
	printf("NULL\n");
}
//ʱ�临�Ӷ�ΪO(n)
//�Կ�����β�壬��һ�����ĵ�ַҲ��ı�
//������Ҫ�����µĵ�һ�����ĵ�ַ��
Node* ListPushBack(Node* head, int val)
{
	//������ڽ���У��ȴ���һ�����
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = val;
	node->next = NULL;
	if (head != NULL)
	{
		Node* cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
	}
	else
		head = node;
	return head;
}
Node* ListPopFront(Node* head)
{
	assert(head != NULL);
	Node* next = head->next;
	free(head);
	return next;
}
Node* ListPopBack(Node* head)
{
	assert(head != NULL);
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		Node* cur = head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		//�ͷ�cur->next�Ŀռ�
		//��cur->next=NULL;
		free(cur->next);
		cur->next = NULL;
	}
	return head;
}