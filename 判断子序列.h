#pragma once
#include<vector>
#include<string>
using namespace std;
//����392
//��Ŀ���ж�������
//��Ŀ�����������ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�
//          �ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ�����
//          �����磬"ace"��"abcde"��һ�������У���"aec"���ǣ���


//˼·1
//˫ָ�룬O��N+M��
bool isSubsequence(string s, string t) {
    int i = 0, j = 0, m = s.size(), n = t.size();
    if (m == 0)  return 1;
    if (n == 0)  return 0;
    while (i < m && j < n)
    {
        if (s[i] == t[j])    i++;
        j++;
    }
    if (i == m && j == n)    return s[m - 1] == t[n - 1] ? 1 : 0;
    if (i == m)  return 1;
    return 0;
}

//˼·2
//dp
//ת��Ϊ������У����������еĳ��ȵ���s���ȣ�˵����s������t��������
bool isSubsequence(string s, string t) {
    int m = s.size(), n = t.size();
    if (m == 0)  return 1;
    if (n == 0)  return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = s[0] == t[0] ? 1 : 0;
    for (int j = 1; j < n; j++)
        if (s[0] == t[j])    dp[0][j] = 1;
        else dp[0][j] = dp[0][j - 1];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = s[i] == t[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m - 1][n - 1] == m;
}