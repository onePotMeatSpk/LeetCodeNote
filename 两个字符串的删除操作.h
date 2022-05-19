#pragma once
#include<vector>
#include<string>
using namespace std;
//力扣583
//题目：不同的子序列
//题目描述：给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
//			每步 可以删除任意一个字符串中的一个字符。

//方法1：编辑距离的缩水版
//与编辑距离相同思考方式
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

//方法2：转化成最长公共子序列
//单词删去子序列之外的字符，不就变成了子序列了吗，删多少个单词，就是多少步
//那么两个单词的步数，就是两个单词删去单词的总数
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