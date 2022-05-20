#pragma once
#include<vector>
#include<string>
using namespace std;
//����516
//��Ŀ�������������
//��Ŀ����������һ���ַ��� s ���ҳ�������Ļ��������У������ظ����еĳ��ȡ�
			//�����ж���Ϊ�����ı�ʣ���ַ�˳�������£�ɾ��ĳЩ�ַ����߲�ɾ���κ��ַ��γɵ�һ�����С�

//dp
//��������Ӵ�������5����ͬ˼·
int longestPalindromeSubseq(string s) {
    int len = s.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    int maxLen = 1;
    for (int i = len - 1; i >= 0; i--)
        for (int j = i; j < len; j++)
            if (s[i] == s[j])
            {
                if (j - i <= 2)  dp[i][j] = j - i + 1;
                else dp[i][j] = dp[i + 1][j - 1] + 2;

                if (maxLen < dp[i][j])   maxLen = dp[i][j];
            }
            else    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);

    return maxLen;
}