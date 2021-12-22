#pragma once
#include<iostream>
#include<string>
using namespace std;
//题目：如标题
//递归进行全排列，注意考虑大数问题

void printNumber(string& s)
{
	string temp;
	int i = 0;
	while (i < s.size())
	{
		if (s[i] == '0')
			i++;
		else
			break;
	}
	while (i < s.size())
	{
		temp += s[i];
		i++;
	}
	if (temp.size())
		cout << temp << endl;
}

void printNumbersCore(int index, string& s) {
	if (index == s.size())
	{
		printNumber(s);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		s[index] = '0' + i;
		printNumbersCore(index + 1, s);
	}
}

void printNumbers(int n)
{
	string s;
	for (int i = 0; i < n; i++)
		s += '0';
	printNumbersCore(0, s);
}