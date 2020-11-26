#include"Queue.h"


int main()
{
	Queue q;

	QListNodeInit(&q);

	QListNodePush(&q, 10);
	QListNodePush(&q, 20);
	QListNodePush(&q, 30);
	QListNodePush(&q, 40);
	QListNodePush(&q, 50);

	printf("%d\n", QListNodeSize(&q));

	QListNodePop(&q);
	QListNodePop(&q);

	printf("%d\n", QListNodeSize(&q));

	QListNodeDestroy(&q);


}