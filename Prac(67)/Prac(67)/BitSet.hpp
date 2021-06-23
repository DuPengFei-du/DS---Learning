#pragma once 

#include<bitset>
#include<iostream>

using namespace std;

void TestBitSet()
{
	std::bitset<100> bt;  //说明我现在给出100个比特位

	//调用方法把对应的比特位置为1

	bt.set(12);  //就是把12这个比特位置为1
	bt.set(23);
	bt.set(45);
	bt.set(78);
	bt.set(90);

	cout << bt.size() << endl;
	cout << bt.count() << endl;

	//test方法用来检测对应的比特位上的值到底是0还是1
	if (bt.test(12))
	{
		cout << "12 bit is 1" << endl;
	}
	else
	{
		cout << "12 bit is 0" << endl;
	}

	//reset的功能是将对应的比特位置0

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