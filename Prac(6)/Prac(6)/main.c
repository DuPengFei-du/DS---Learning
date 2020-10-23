#include"Queue.h"


int main()
{
	QList q;

	QListInit(&q);

	QListPush(&q, 10);
	QListPush(&q, 20);
	QListPush(&q, 30);
	QListPush(&q, 40);
	QListPush(&q, 50);

	printf("%d\n", QListEmpty(&q));
	printf("%d\n", QListSize(&q));

	QListPop(&q);
	QListPop(&q);

	printf("%d\n", QListEmpty(&q));
	printf("%d\n", QListSize(&q));

	QListDestroy(&q);
}