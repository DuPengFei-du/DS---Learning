#include"shun.h"

void SeqListInit(SeqList* seq)
{
	assert(seq);
	seq->array = (int*)malloc(sizeof(int) * Dafault_Capacity);
	if (NULL == seq)
	{
		assert(0);
		return;
	}
	seq->_capacity = Dafault_Capacity;
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

void CheckCapacity(SeqList* seq)
{
	assert(seq);
	if (seq->_capacity == seq->_size)
	{
		int newcapacity = 2 * Dafault_Capacity;
		int* temp = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//Ԫ�ؿ���
		memcpy(temp, seq->array, sizeof(int) * seq->_size);
		free(seq->array);
		seq->array = temp;
		seq->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* seq, int val)
{
	assert(seq);
	CheckCapacity(seq);
	seq->array[seq->_size] = val;
	seq->_size++;
}

void SeqListPrint(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i < seq->_size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
	return;
}

void SeqListPushFront(SeqList* seq, int val)
{
	assert(seq);
	CheckCapacity(seq);
	for (int i = seq->_size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->_size++;
}

void SeqListPopFront(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i <= seq->_size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->_size--;
}

void SeqListInsert(SeqList* seq, int index, int val)
{
	assert(seq);
	//��Ҫ�ж�һ���������±�ĺϷ���
	if (index<0 || index>seq->_size)
	{
		printf("�����±�Ƿ�������������!");
		return;
	}
	else
	{
		//��ȥ��������Ƿ���
		CheckCapacity(seq);
		for (int i = seq->_size - 1; i >= index; i--)
		{
			seq->array[i + 1] = seq->array[i];
		}
		seq->array[index] = val;
		seq->_size++;
	}
}

void SeqListErase(SeqList* seq, int index)
{
	//ȷ��˳������
	assert(seq);
	for (int i = index; i <= seq->_size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->_size--;
}

int SeqListSize(SeqList* seq)
{
	assert(seq);
	if (0 == seq->_size)
		return 0;
	else
		return seq->_size;
}

int SeqListCapacity(SeqList* seq)
{
	assert(seq);
	return seq->_size;
}

int SeqListFind(SeqList* seq, int data)
{
	assert(seq);
	for (int i = 0; i < seq->_size; i++)
	{
		if (seq->array[i] == data)
			return i;
	}
	return -1;
}

int SeqListEmpty(SeqList* seq)
{
	return seq->_size == 0 ? 1 : 0;
}

void SeqListRemove(SeqList* seq, int data)
{
	assert(seq);
	SeqListErase(seq, SeqListFind(seq, data));
}

void SeqListRemoveAll(SeqList* seq, int data)
{
	//�������ַ�����ʱ�临�ӶȽӽ�N^2
	assert(seq != NULL);
	int index = -1;
	while (-1 != SeqListFind(seq, data))  //������˵�����ҵ���
	{
		SeqListErase(seq, index);
	}
	//������ͨ��һ���������������Erase
	//������ͨ���ṩ�����ռ䣬��ʱ�ռ临�Ӷ�ΪO(N),ʱ�临�Ӷ�Ϊ0(N)
	/*
	int count=0;   //��¼��ɾ��Ԫ�صĸ���
	for(int i=0;i<seq->_size;i++)
	{
	  if(data==seq->array[i])
		 count++;
	  else
		 seq->array[i-count]=seq->array[i];
	 }
	 //���ַ�����ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1)
	*/
}