#pragma once
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<typeinfo>
#include"四数之和.h"
using namespace std;

void main()
{
    vector<int> next = getNext("issip");
    for (int i = 0; i < next.size(); i++)
        cout << i << " ";
    cout << endl;
	return;
}
