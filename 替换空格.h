#pragma once
#include<string>
//题目：请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
using namespace std;

string replaceSpace(string s) {
	string newS;
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			newS += "%20";
		else
			newS += s[i];

		i++;
	}

	return newS;
}