#pragma once
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<typeinfo>
#include"����֮��.h"
using namespace std;

void main()
{
    vector<int> next = getNext("issip");
    for (int i = 0; i < next.size(); i++)
        cout << i << " ";
    cout << endl;
	return;
}
