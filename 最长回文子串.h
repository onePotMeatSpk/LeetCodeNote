#pragma once
#include<vector>
#include<string>
using namespace std;
//����5
//��Ŀ��������Ӵ�
//��Ŀ����������һ���ַ��� s���ҵ� s ����Ļ����Ӵ���

//������Ӵ�������647����ͬ˼·��ֻ�����������Ӵ��м�¼�Ӵ�������num�������˼�¼����ȵ�maxLen�ͼ�¼�Ӵ���ʼ�����start
string longestPalindrome(string s) {
    int len = s.size();
    vector<vector<bool>> dp(len, vector<bool>(len, 0));
    int maxLen = 0, start = 0;
    for (int i = len - 1; i >= 0; i--)
        for (int j = i; j < len; j++)
            if (s[i] == s[j])
            {
                if (j - i <= 2)  dp[i][j] = 1;
                else    dp[i][j] = dp[i + 1][j - 1];

                if (dp[i][j] && maxLen < j - i + 1)
                {
                    maxLen = j - i + 1;
                    start = i;
                }
            }

    return s.substr(start, maxLen);
}