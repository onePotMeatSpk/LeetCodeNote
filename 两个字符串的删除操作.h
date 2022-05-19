#pragma once
#include<vector>
#include<string>
using namespace std;
//����583
//��Ŀ����ͬ��������
//��Ŀ������������������ word1 �� word2 ������ʹ�� word1 ��  word2 ��ͬ�������С������
//			ÿ�� ����ɾ������һ���ַ����е�һ���ַ���

//����1���༭�������ˮ��
//��༭������ͬ˼����ʽ
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, dp[i][j - 1] + 1});

    return dp[m][n];
}

//����2��ת���������������
//����ɾȥ������֮����ַ������ͱ��������������ɾ���ٸ����ʣ����Ƕ��ٲ�
//��ô�������ʵĲ�����������������ɾȥ���ʵ�����
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = word1[0] == word2[0];
    for (int j = 1; j < n; j++)
        if (word1[0] == word2[j])    dp[0][j] = 1;
        else    dp[0][j] = dp[0][j - 1];
    for (int i = 1; i < m; i++)
        if (word2[0] == word1[i])    dp[i][0] = 1;
        else    dp[i][0] = dp[i - 1][0];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = word1[i] == word2[j] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);

    return m + n - 2 * dp[m - 1][n - 1];
}