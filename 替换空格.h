#pragma once
#include<string>
//��Ŀ����ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
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