#include"shun.h"


void SeqListInit(SeqList* seq)
{
	//������Ҫ�ȿ�һ�����˳����Ƿ����
	assert(seq);
	seq->array = (int*)malloc(sizeof(int) * Default_Capacity);
	//���ٿռ��ˣ��ҽ�������Ҫ��һ���ҿ��ٵĿռ��Ƿ񿪱ٳɹ���
	if (NULL == seq->array)
	{
		assert(0);
		return NULL;
	}
	seq->size = 0;
	seq->capacity = Default_Capacity;
}

void CheckCapacity(SeqList* seq)
{
	assert(seq);
	if (seq->size = seq->capacity)
	{
		//֤��û�пռ��ˣ���Ҫ������
		int newcapacity = 2 * Default_Capacity;
		int* NewArray = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == NewArray)
		{
			assert(0);
			return;
		}
		memcpy(NewArray, seq->array, sizeof(int) * seq->size);
		//�ͷžɿռ�
		free(seq->array);
		seq->array = NewArray;
		seq->capacity = newcapacity;
	}
}

void SeqListDestroy(SeqList* seq)
{
	free(seq->array);
	//�ͷ���֮���һ���Ҫ�������óɿ�ֵ
	seq->array = NULL;
	seq->capacity = 0;
	seq->size = 0;
}