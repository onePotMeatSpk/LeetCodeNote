#pragma once
#include<iostream>
using namespace std;
int add(int a, int b) {
	int c;
	while (b != 0)
	{
		c = ((unsigned int)a & (unsigned int)b) << 1;//某些编译器不支持负数左移，故而先做unsigned int处理
		a = a ^ b;
		b = c;
	}
	return a;
}