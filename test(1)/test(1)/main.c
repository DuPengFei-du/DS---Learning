//逆向打印单链表
//思路1：使用递归的思路
void PrintTailtoHead(phead)
{
	if (phead)
	{
		PrintTailtoHead(phead->next);
	}
	printf("%d ", phead->data);
	return 0;
}


//思路2：标记结点，这个标记的结点是所要打印结点的下一个结点
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
