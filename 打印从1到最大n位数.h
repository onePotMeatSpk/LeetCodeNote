#pragma once
#include<iostream>
#include<string>
using namespace std;
//题目：输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
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