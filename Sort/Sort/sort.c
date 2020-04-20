#include"sort.h"

void PrintArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

//�����������ȶ��������㷨
//ʱ�临�Ӷ�ΪO(N^2)
//�ռ临�Ӷ�Ϊ0(1),û�н��������Ŀռ�
//���ų���Ϊ��������������Ѿ����������ˣ�ʱ�临�Ӷ�ΪO(N)
//���ó����������˳���Ѿ����������ˣ����������Ǻܴ�(�ȽϵĴ������Լ���)
void InsertSort(int* array, int size)
{
	for (int i = 1; i < size; ++i)
	{
		//��¼��ǰ��Ҫ�Ƚϵ�Ԫ��
		int key = array[i];
		int end = i - 1;  //�ǵ�ǰԪ�ص�ǰһ��Ԫ��
		//�д������λ��
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;
	}
}

//ϣ������Ŀռ临�Ӷ���O(1)
//�ȶ���:ϣ�������ǲ��ȶ������򷽷�
//��Ϊϣ�������ڽ��в����ʱ���������ŷ�����в���ģ������������ǲ��ȶ���
//ϣ����������ó������������󣬱Ƚ�����
void ShellSort(int* array, int size)
{
	int gap = size;
	//gap��ѡȡ�ж���֮ǰ����������ķ���
	//(1)gapȡһϵ�е�����; (2)gap/3+1;
	//ϣ����������ʱ�临�Ӷ��ǲ��ø��ģ���Ϊϣ�������ʱ�临�Ӷ�
	//�ܵ�gapȡֵ��Ӱ��
	//���ݴ����ļ���ó���gap=gap/3+1��ʱ�临�Ӷȿ��Դ���
	//N^1.25~1.6N^1.25 ֮�������һ��ʱ�临�Ӷ�
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; ++i)
		{
			//��¼��ǰ��Ҫ�Ƚϵ�Ԫ��
			int key = array[i];
			int end = i - gap;  //�ǵ�ǰԪ�ص�ǰһ��Ԫ��
			//�д������λ��
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap -= 1;
	}
}

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void SelectSort(int* array, int size)
{
	for (int i = 0; i < size - 1 ; ++i)
	{
		int maxPos = 0;    //maxPos�����������Ԫ�����ڵ�λ��
		for (int j = 0; j < size - i ; ++j)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}
		Swap(&array[maxPos], &array[size-i - 1]);
	}
}