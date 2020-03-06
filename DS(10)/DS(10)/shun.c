#include"shun.h"


void SeqListInit(SeqList* seq)
{
	//�ȿ������˳����Ƿ����
	assert(seq);
	seq->array = (int*)malloc(sizeof(int) * Default_Capacity);
	//�鿴����Ŀռ��Ƿ�ɹ�
	if (NULL == seq->array)
	{
		assert(0);
		return;
	}
	seq->_capacity = Default_Capacity;
	seq->_size = 0;
}

void SeqListDestroy(SeqList* seq)
{
	assert(seq);
	free(seq->array);
	seq->array = NULL;
	seq->_capacity = 0;
	seq->_size = 0;
}

//���ݲ���
void CheckCapacity(SeqList* seq)
{
	assert(seq);
	if (seq->_capacity == seq->_size)
	{
		//֤���Ѿ�����
		int newcapacity = 2 * Default_Capacity;
		int* NewArray = (int*)malloc(sizeof(int) * Default_Capacity);
		//�鿴�Ƿ񿪱ٳɹ�
		if (NULL == NewArray)
		{
			assert(0);
			return;
		}
		memcpy(NewArray, seq->array, sizeof(int) * seq->_size);
		free(seq->array);
		seq->array = NewArray;
		seq->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* seq, int val)
{
	assert(seq);
	//�鿴һ�������Ƿ���
	CheckCapacity(seq);  //�����в���������
	seq->array[seq->_size] = val;
	seq->_size++;
}
