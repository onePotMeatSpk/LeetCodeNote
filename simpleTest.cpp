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
	vector<int> v{ 1, 0, -1, 0, -2, 2 };
	fourSum(v, 0);
	return;
}