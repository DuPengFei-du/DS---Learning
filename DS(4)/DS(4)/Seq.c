#include"Seq.h"

void SeqListInit(SeqList* ps)
{
	//ps��ָ�룬���������Լ��ָ��ĺϷ���
	assert(ps);  //��assert���һЩ��Ҫȷ�����ȴ����˳����ǿյ�˳���
	//����ʹ�� 
	/*
	if(NULL==ps)
	return ;
	*/
	//Ĭ�������˳����п��Դ��10��Ԫ��
	ps->_array = (DataType*)malloc(sizeof(DataType) * Dafault_Capacity);
	if (NULL == ps->_array)
	{
		//assert���������ö��Դ���
		//�Ŷ��Եĺô��ǿ���֪������ռ䵽����û�гɹ�
		//ͬʱassert��һ�����Ժ�
		//��ֻ����Debug�汾�²Ż�������
		//����һ�㷢���İ汾����Release�汾
		//Release�汾�����һϵ�е��Ż���������һ�����ǻ��assertɾ��
		assert(0);
		return;
	}
	ps->_capacity = Dafault_Capacity;
	ps->_size = 0;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

//��������ĺ�������Ҫ��������֪���������Ҳ���Ҫ�������������ͷ�ļ���
//ֱ�ӷ��ڶ����ļ��оͿ�����
void CheckCapaciy(SeqList* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		//�ȸ�һ���µĿռ䣬Ȼ�󿽱�Ԫ�أ���ɾ���ɿռ�Ϳ�����
		int newCapacity = 2 * Dafault_Capacity;
		//�����µĿռ�
		DataType* temp = (DataType*)malloc(sizeof(DataType) * newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//����Ԫ��
		memcpy(temp, ps->_array, ps->_size * sizeof(DataType));
		free(ps->_array);
		ps->_array = temp;
		ps->_capacity = newCapacity;
	}
}

void SeqListPushBack(SeqList* ps, DataType data)
{
	assert(ps);
	//��������Ƿ���
	CheckCapaicty();
	ps->_array[ps->_size] = data;
	ps->_size++;
	//�������û�пռ��˵Ļ���ô��
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (0 == ps->_size)
		return;
	ps->_size--;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void SeqListPushFront(SeqList* ps, DataType data)
{
	assert(ps);
	//��Ҫ���ռ��Ƿ���
	CheckCapacity();
	for (int i = ps->_size - 1; i >= 0; i--)
	{
		//��˳�������ЧԪ������������һλ
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[0] = data;
	ps->_size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	if (0 == ps->_size)
		return;
	for (int i = 0; i < ps->_size-1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(SeqList* ps, int pos, DataType data)
{
	assert(ps);
	//���ж��±�ĺϷ���
	if (pos<0 || pos>ps->_size)
		printf("����Ԫ��λ�÷Ƿ�\n");
	//Ȼ���������Ƿ���
	CheckCapacity();
	for (int i = ps->_size - 1; i >= pos; i--)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	if (pos < 0 || pos >= ps->_size)
		printf("ɾ��Ԫ��λ�÷Ƿ�\n");
	for (int i = pos; i <= ps->_size - 2; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

int SeqListFind(SeqList* ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
			return i;
	}
	return -1;
}

int SeqListSize(SeqList* ps)
{
	assert(ps);
	return ps->_size;
}

int SeqLisCapacity(SeqList* ps)
{
	assert(ps);
	return ps->_capacity;
}

int SeqLisEmpty(SeqList* ps)
{
	assert(ps);
	if (0 == ps->_size)
		return 1;
	else
		return 0;
}

DataType SeqListFront(SeqList* ps)
{
	assert(ps);
	return ps->_array[0];
}

DataType SeqListBack(SeqList* ps)
{
	assert(ps);
	return ps->_array[ps->_size];
}

void SeqListRemove(SeqList* ps, DataType data)
{
	SeqListErase(ps,SeqListFind(ps, data));   //����
}

void SeqListRemoveAll(SeqList* ps, DataType data)
{
	/*
	int pos=-1;
	while(-1!=(pos=SeqListFind(ps,data)))
	{
	   SeqListErase(ps,pos);
	}
	*/

	/*
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			SeqListErase(ps, i);
		}
	}
	*/

	int count = 0;   //��¼��ɾ��Ԫ�صĸ���
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
			count++;
		else
			ps->_array[i - count] = ps->_array[i];
	}
}
