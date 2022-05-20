#pragma once
#include<vector>
#include<string>
using namespace std;
//����647
//��Ŀ�������Ӵ�
//��Ŀ����������һ���ַ��� s ������ͳ�Ʋ���������ַ����� �����Ӵ� ����Ŀ��
		//�����ַ��� �����Ŷ��͵�������һ�����ַ�����
		//���ַ��� ���ַ����е��������ַ���ɵ�һ�����С�
		//���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ������ͬ���ַ���ɣ�Ҳ�ᱻ������ͬ���Ӵ���

//����������¼
int countSubstrings(string s) {
    int len = s.size();
    vector<vector<bool>> dp(len, vector<bool>(len, 0));
    int num = 0;

    for (int i = len - 1; i >= 0; i--)
        for (int j = i; j < len; j++)
            if (s[i] == s[j])
                if (abs(i - j) <= 2)
                {
                    dp[i][j] = 1;
                    num++;
                }
                else if (dp[i][j] = dp[i + 1][j - 1])
                    num++;
    return num;
}