#pragma once
#include<string>
#include<vector>
using namespace std;
//����459
//��Ŀ���ظ������ַ���
//��ɣ�����һ���ǿյ��ַ��� s ������Ƿ����ͨ��������һ���Ӵ��ظ���ι��ɡ�

//KMP�㷨
//���len % (len - (next[len - 1])) == 0 ����˵��(���鳤�� - ����ǰ��׺�ĳ���) ���ÿ��Ա� ����ĳ���������˵���и��ַ������ظ������ַ�����
//���鳤�ȼ�ȥ���ͬǰ��׺�ĳ����൱���ǵ�һ�����ڵĳ��ȣ�Ҳ����һ�����ڵĳ��ȣ����������ڿ��Ա���������˵�������������������ڵ�ѭ����

//���������next���飬next[i]��[0, i]������ǰ׺�ĳ���
vector<int> getNext(string s)
{
    vector<int> next(s.size(), 0);

    int j = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (j > 0 && s[i] != s[j])
            j = next[j - 1];

        if (s[i] == s[j])
            next[i] = ++j;
    }

    return next;
}

//������
bool repeatedSubstringPattern(string s)
{
    int len = s.size();
    vector<int> next = getNext(s);
    for (int i : next)

    //����
    if (next[len - 1] != 0 && (len % (len - next[len - 1]) == 0))
        return 1;
    else
        return 0;
}