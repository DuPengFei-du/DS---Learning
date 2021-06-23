#pragma once 

#include<bitset>
#include<iostream>

using namespace std;

void TestBitSet()
{
	std::bitset<100> bt;  //˵�������ڸ���100������λ

	//���÷����Ѷ�Ӧ�ı���λ��Ϊ1

	bt.set(12);  //���ǰ�12�������λ��Ϊ1
	bt.set(23);
	bt.set(45);
	bt.set(78);
	bt.set(90);

	cout << bt.size() << endl;
	cout << bt.count() << endl;

	//test������������Ӧ�ı���λ�ϵ�ֵ������0����1
	if (bt.test(12))
	{
		cout << "12 bit is 1" << endl;
	}
	else
	{
		cout << "12 bit is 0" << endl;
	}

	//reset�Ĺ����ǽ���Ӧ�ı���λ��0

	bt.reset(12);

	if (bt.test(12))
	{
		cout << "12 bit is 1" << endl;
	}
	else
	{
		cout << "12 bit is 0" << endl;
	}
}