//�����ӡ������
//˼·1��ʹ�õݹ��˼·
void PrintTailtoHead(phead)
{
	if (phead)
	{
		PrintTailtoHead(phead->next);
	}
	printf("%d ", phead->data);
	return 0;
}


//˼·2����ǽ�㣬�����ǵĽ������Ҫ��ӡ������һ�����
void PrintList(Node* head)
{
	Node *cur = NULL;
	Node *pTailNode = NULL;
	cur = phead;
	while (pTailNode != head)
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		printf("%d ", cur->data);
		pTailNode = cur;
	}
}
