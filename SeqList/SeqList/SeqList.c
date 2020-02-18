#include"SeqList.h"

static void CheckCapacity(SeqList *seq)
{
	assert(seq != NULL);
	if (seq->_size == seq->_capacity)
	{
		int newCapacity = 2 * DefaultCapacity;
		DataType* newArray = (DataType*)malloc(sizeof(DataType) * newCapacity);
		if (NULL == newArray)
		{
			assert(0);
			return ;
		}
		memcpy(newArray, seq->array, seq->_size * sizeof(DataType));
		//�ͷžͿռ�
		free(seq->array);
		seq->array = newArray;
		seq->_capacity = newCapacity;
	}
}

void SeqListInit(SeqList* seq)
{
	assert(seq != NULL);  //�ȼ������ĺϷ��ԣ�Ȼ���ٸ����㷨�Ĺ���
	seq->array = (DataType*)malloc(sizeof(DataType) * DefaultCapacity);
	if (NULL == seq->array)
	{
		assert(0);  //assert�ǵ��Ժֻ꣬����Debug�汾����������
		return;
	}
	//���if��������˵������ռ��Ѿ��ɹ���
	seq->_size = 0;
	seq->_capacity = DefaultCapacity;
}

void SeqListDestroy(SeqList* seq)
{
	free(seq->array);
	seq->array = NULL;
	seq->_size = 0;
	seq->_capacity = 0;
}

void SeqListPushBack(SeqList* seq, DataType data)  //β��
{
	assert(seq != NULL);
	CheckCapacity(seq);
	seq->array[seq->_size] = data;
	seq->_size++;
	//�����ڶ�̬˳����л���Ҫ�����Ƿ���Ҫ���ݵ�����
	//�������Ƿ��ã�Ȼ���Ƿ���Ҫ����
}

void SeqListPopBack(SeqList* seq)   //βɾ
{
	assert(seq != NULL);
	if (0 == seq->_size)
		return;
	seq->_size--;
}

void SeqListPrint(SeqList* seq)
{
	assert(seq);
	int i = 0;
	for (i = 0; i < seq->_size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
}

void SeqListPushFront(SeqList* seq, DataType data)
{
	assert(seq != NULL);
	//����Ҫ���ռ��Ƿ����
	CheckCapacity(seq);
	//����Ԫ�صĲ���
	for (int i = seq->_size-1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = data;
	seq->_size++;
}

void SeqListPopFront(SeqList* seq)
{
	assert(seq != NULL);
	if (0 == seq->_size)
		return;
	else
	{
		for (int i = 0; i < seq->_size; i++)
		{
			seq -> array[i] = seq->array[i + 1];
		}
	}
	seq->_size--;
}

void SeqListInsert(SeqList* seq,int index,DataType data)
{
	assert(seq != NULL);
	//����Ҫ�ж�һ���������±�ĺϷ���
	if (index<0 || index>seq->_size)
	{
		printf("��������±�Ϊ�Ƿ��±꣬����������!");
		return;
	}
	//Ȼ����Ҫ��������Ƿ���
	CheckCapacity(seq);
	for (int i = seq->_size - 1; i >= index; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[index] = data;
	seq->_size++;
}

void SeqListErase(SeqList* seq, int index)
{
	assert(seq != NULL);
	if (index<0 || index>seq->_size)
	{
		printf("��������±�Ϊ�Ƿ��±꣬����������!");
		return;
	}
	for (int i = index; i <= seq->_size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->_size--;
}

int SeqListFind(SeqList* seq, DataType data)
{
	assert(seq != NULL);
	for (int i = 0; i < seq->_size; i++)
	{
		if (seq->array[i] == data)
			return i;
	}
	return -1;
}

void SeqListRemove(SeqList* seq, DataType data)
{
	assert(seq != NULL);
	SeqListErase(seq, SeqListFind(seq, data));
}

void SeqListRemoveAll(SeqList* seq, DataType data)
{
	//�������ַ�����ʱ�临�ӶȽӽ�N^2
	assert(seq != NULL);
	int index = -1;
	while (-1 == SeqListFind(seq, data))
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
	     seq->array[i-cout]=seq->array[i];
     }
	 //���ַ�����ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1)
	*/
}

int SeqListSize(SeqList* seq)
{
	assert(seq != NULL);
	return seq->_size;
}

int SeqListCapacity(SeqList* seq)
{
	assert(seq != NULL);
	return seq->_capacity;
}

int SeqListEmpty(SeqList* seq)
{
	assert(seq != NULL);
	if (0 == seq->_size)
		return 0;
	else
		return 1;
}

DataType SeqListFront(SeqList* seq)
{
	assert(seq != NULL);
	return seq->array[0];
}

DataType SeqListLast(SeqList* seq)
{
	assert(seq != NULL);
	return seq->array[seq->_size - 1];   //������ǰ��--�ͺ���--��ʹ�õĻ���˳����Ԫ�ظ����ͻ���1
}