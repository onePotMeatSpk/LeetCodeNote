#pragma once
#include<iostream>
using namespace std;
int add(int a, int b) {
	int c;
	while (b != 0)
	{
		c = ((unsigned int)a & (unsigned int)b) << 1;//ĳЩ��������֧�ָ������ƣ��ʶ�����unsigned int����
		a = a ^ b;
		b = c;
	}
	return a;
}