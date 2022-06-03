#pragma once
#include<iostream>
#include"LFU»º´æ.h"
using namespace std;

void main()
{
	LFUCache cache(0);

	cache.put(0, 0);

	cout << "get(0)=" << cache.get(0) << endl;

	return;
}