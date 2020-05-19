#include"Heap.h"

void Swap(HPDataType* x, HPDataType* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//���µ�������ô����Ҫ���µ�������˭�أ���ʵ����hp�������
//�����������ڴ�������С��
//��ô�����Ǿ���Ҫ��ȥ���parent�Ƿ�Ⱥ���С
//parent�ĺ��ӿ��������������parent�Ƚ�С���Ǹ����ӻ�С�Ļ�����ô
//parent�϶����������Ӷ�ҪС
//���parent����������Ҫ����ô�Ͳ�����ѵ����ԣ���ô��Ҫ�������µ���
//�Ĳ������ѽϴ��˫�����½����ƶ������ܻᵼ��������������������ô
//����Ҫ�������½��е���
void AdjustDown(Heap* hp, int parent)
{
	//parent������Ҫ������Ԫ���ڶѽṹ�е��±�
	//child����parent�����������н�С��һ����Ĭ��child��ʾ����
	//parent�����ӣ���Ϊ����ȫ�������У�һ�������������ӵ�ͬʱû���Һ���
	int child = parent * 2 + 1;
	//whileѭ���������жϣ���֤���Ӵ��ڣ�������Ӳ����ڣ�˵��parentû�к���
	while (child < hp->_size)
	{
		//������Ҫ��֤�Һ���Ҳ���ڣ�Ȼ����ȥ�����������н�С�ĺ���
		if (child+1 < hp->_size && hp->array[child + 1] < hp->array[child])
		{
			child = child + 1;
		}
		//���˫�״�Ļ����ͽ��н���
		if (hp->array[child] < hp->array[parent])
		{
			Swap(&hp->array[parent], &hp->array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
//���µ�����ʱ�临�Ӷȣ������Ŀ����µ����Ļ������������������������Ǵ���������Ǹ���㿪ʼ����
//��ô�����Ĵ�����Ҳ��ʵ�������ĸ߶ȣ����ĸ߶ȵ��󷨾���log2(n+1)������ȡ��
//�������µ�����ʱ�临�ӶȾ���log2(N)

void AdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) >> 1;
	while (child)
	{
		if (hp->array[child] < hp->array[parent])
		{
			Swap(&hp->array[child], &hp->array[parent]);

			//С��Ԫ�������ƶ������ܻᵼ���ϲ㲻����ѵ��ض�
			//����Ҫ�������ϵ���
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			return;
		}
	}
}


//���Ѿ����ڲ��ϵص������µ����ķ������������Ƿ�Ҷ�ӽ�㣬����ռ�����н���һ��
//��ô���ǵ��������н��һ��Ĵ��������µ���
//���Խ��ѵ�ʱ�临�Ӷ�Ϊ---------------------nlog2(N)   ������û��ǲ�һ�½��ѵ�ʱ�临�Ӷ�
void HeapCreate(Heap* hp, HPDataType arr[], int size)
{
	assert(hp);
	//1.�Ƚ�arr�е�Ԫ�طŵ��ѵĽṹ��
	hp->array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->_capacity = size;
	memcpy(hp->array, arr, sizeof(HPDataType) * size);
	hp->_size = size;

	//2.Ȼ��ȥ��ʼ���ѵĽṹ
	//�����һ����Ҷ�ӽ�㿪ʼ���е���
	for (int root = (size - 2) >> 1; root >= 0; root--)
	{
		AdjustDown(hp, root);
	}
}

void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size >= hp->_capacity)
	{
		int newcapacity = 2 * hp->_capacity;
		HPDataType* temp = (HPDataType*)malloc(sizeof(HPDataType) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, hp->array, sizeof(HPDataType) * hp->_size);
		//���ַ�������Ԫ�صĿ���������
		/*for (int i = 0; i < hp->_size; ++i)
		{
			temp[i] = hp->array[i];
		}
		*/
		free(hp->array);
		hp->array = temp;
		hp->_capacity = newcapacity;
	}
}

void HeapPush(Heap* hp, HPDataType data)
{
	assert(hp);
	CheckCapacity(hp);
	hp->array[hp->_size ++] = data;
	AdjustUp(hp, hp->_size - 1);
}

//�ѵ�ɾ����ɾ�����ǶѶ���Ԫ�أ���Ϊ�Ѷ���Ԫ������ֵ(�������ֵ��������Сֵ)
//һ��ʼ���뵽˳���ͷɾ�ķ�����������ʵ������ɾ���ǲ����Եģ���Ϊ���ƻ���ԭ�еĽṹ
//���Ծ�������˰Ѷѵ����һ��Ԫ�غͶѵĵ�һ��Ԫ���Ƚ���λ�ã�Ȼ��ѵ���ЧԪ�صĸ���-1
//Ȼ��ԶѶ�Ԫ�ؽ��е����Ϳ�����
void HeapPop(Heap* hp)
{
	assert(hp);
	if (HeapEmpty(hp))
		return;
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp, 0);
}

//��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* hp)
{
	assert(hp && !HeapEmpty(hp));  //Ҫ��ȡ�Ѷ�Ԫ�صĻ���Ҫ��֤�Ѵ��ڣ�ͬʱҪ��֤���Ƿǿյ�
	return hp->array[0];
}

//��ȡ����Ԫ�صĸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	if (hp->array)
	{
		free(hp->array);
		hp->array = NULL;
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

void HeapAdjust(int array[], int size, int parent)
{
	//���µ���
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] < array[child])
			child += 1;
		if (array[child] < array[parent])
		{
			int temp = array[child];
			array[child] = array[parent];
			array[parent] = temp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;  //���ӱ�˫�״�
		}
	}
}

void HeapSort(int array[], int size)
{
	//1.����
	//����Ҫ���ҵ�������һ����Ҷ�ӽ��
	for (int root = (size - 2) >> 1; root >= 0; --root)
	{
		HeapAdjust(array, size, root);   //�ѵ���
	}
	//2.���ö�ɾ����˼������������
	int end = size - 1;  //�������һ��Ԫ��
	while (end)
	{
		int temp = array[0];
		array[0] = array[end];
		array[end] = temp;
		HeapAdjust(array, end, 0);
		end--;
	}

}

void TestFunc()
{
	int arr[] = { 5,3,8,4,2,7,6,1,0 };

	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));

	Heap hp;

	HeapCreate(&hp,arr,sizeof(arr)/sizeof(arr[0]));

	printf("size == %d\n", HeapSize(&hp));

	printf("top == %d\n", HeapTop(&hp));

	HeapPop(&hp);

	printf("size == %d\n", HeapSize(&hp));

	printf("top == %d\n", HeapTop(&hp));

	HeapPush(&hp,9);

	printf("size == %d\n", HeapSize(&hp));

	printf("top == %d\n", HeapTop(&hp));

	HeapPush(&hp, 0);

	printf("size == %d\n", HeapSize(&hp));

	printf("top == %d\n", HeapTop(&hp));
}