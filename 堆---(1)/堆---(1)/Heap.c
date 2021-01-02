#include"Heap.h"


//��ʼ��һ���ն�
void HeapInit(Heap* hp,int init)
{
	assert(hp);
	init = init < 10 ? 10 : init; 
	//���С��10�Ļ����͸���10������Ļ����͸�����������Ϳ�����
	//��֤���ٿ���10���ڴ�ռ�
	hp->array = (HDataType*)malloc(sizeof(HDataType)* init);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->size = init;
	hp->capacity = 10;
}

void Swap(HDataType* left, HDataType* right)
{
	HDataType temp = *left;
	*left = *right;
	*right = temp;
}

int Less(HDataType left, HDataType right)
{
	return left < right;
}

int Greater(HDataType left, HDataType right)
{
	return left < right;
}

void AdjustDown(HDataType* array, int size, int parent)
{
	//��child���parent�н�С�ĺ���---Ĭ���ȱ����ߵĺ���
	//��Ϊ����ɺ��ӵĻ�����ô�϶�����������
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child+1<size&&array[child + 1] < array[child])
		{
			child += 1;
		}
		//Ȼ����˫���Ƿ�����ѵ�����
		if (array[parent] > array[child])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

//�������е�Ԫ�ش�����
void HeapCreate(Heap* hp, int* array, int size)
{
	int root = 0;
	//1.�Ƚ������е�Ԫ�ط��ڶѽṹ����
	HeapInit(hp, size);  //���������ڴ�ռ䣬����size���ռ�Ĵ�С
	//�ռ俪�ٺ���֮��ֻ��Ҫ�������е�Ԫ�طŽ����ͺ���
	memcpy(hp->array, array, sizeof(HDataType) * size);
	hp->size = size;

	//2.��ʼ���е���
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->size, root);   //Ҫ�����ľ���hp���Ǹ�����
		//Ҫ������Ԫ�ظ�������hp->size��Ԫ��
	}
}

HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];   //����0��λ��Ԫ����ʵ���ǶѶ���Ԫ��
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

void AdjustUp(HDataType* array, int size, int child)
{
	int parent  = ((child - 1) >> 1);
	while (child)   //ѭ����������Ϊ��ֻҪchildû���ߵ�������λ���ϣ�ѭ���ͻ�һֱ�Ľ�����ȥ
	{
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			return;  //����������Ļ���ֱ��return�Ϳ�����
	}

}

void CheckCapacity(Heap* hp)
{
	//���������һ�����Ƿ���Ҫ������ѽ������ݵĲ���
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = 2 * hp->capacity;
		HDataType* temp = (HDataType*)malloc(sizeof(HDataType) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//����Ԫ�صķ�ʽ��ʵ����������ʽ��
		//1.memcpy(temp, hp->array, sizeof(HDataType) * hp->size);
		for (int i = 0; i < hp->size; ++i)
		{
			temp[i] = hp->array[i];
		}
		free(hp->array);
		hp->array = temp;
		hp->capacity = newcapacity;
	}
}

void HeapPush(Heap* hp, HDataType data)
{
	//0.�Ͼ��ѵײ�Ŀռ������޵ģ����ǲ���������ֹ��ȥ����
	//�������ǻ���Ҫ�Զѵײ�ռ���������м��
	//����Ƿ���Ҫ����

	CheckCapacity(hp);
	//1.���ȣ�������Ҫ����Ԫ�ؽ��в���Ĳ���
	//�����뵽��λ���������ĩβ
	hp->array[hp->size] = data;
	hp->size++;

	//��Ȼ����Ϊ��������Ԫ�صĲ��룬��ô����Ԫ�صĲ���ʱ���п���
	//���¶ѵ����ʱ��ƻ���
	//��ô�����ʱ����Ҫ��������������ϵ���
	AdjustUp(hp->array, hp->size, hp->size - 1);
}

void HeapPop(Heap* hp)   //ɾ����ʵ��Ҫɾ���ľ��ǶѶ���Ԫ��
{
	//���Ѷ�Ԫ�غ����һ��Ԫ�ؽ��н���
	//Ȼ��Ԫ�صĸ�������һ��
	Swap(&hp->array[0], &hp->array[hp->size-1]);
	hp->size--;
	AdjustDown(hp->array, hp->size, 0);   //0����˼����Ҫ������Ԫ���ǶѶ�Ԫ��
}

void HeapDestroy(Heap* hp)  //����
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}

//////////////////////////////////////////////////
void TestHeap()
{
	int array[] = { 3,6,9,1,5,0,7,8,4,2 };

	Heap hp;

	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]));

	printf("heap size =%d\n", HeapSize(&hp));

	printf("heap top =%d\n",HeapTop(&hp));

	HeapPop(&hp);

	printf("heap size =%d\n", HeapSize(&hp));

	printf("heap top =%d\n", HeapTop(&hp));

	HeapPush(&hp,-1);

	printf("heap size =%d\n", HeapSize(&hp));

	printf("heap top =%d\n", HeapTop(&hp));

	HeapDestroy(&hp);
}
