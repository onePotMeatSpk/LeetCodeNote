#pragma once
#include<vector>
#include<string>
using namespace std;
//力扣115
//题目：不同的子序列
//题目描述：给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
//          字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

//见代码随想录
int numDistinct(string s, string t) {
    int m = t.size(), n = s.size();
    if (m == 0)  return 1;
    if (n == 0)  return 0;

    vector<vector<unsigned int>> dp(m, vector<unsigned int>(n, 0));
    dp[0][0] = s[0] == t[0];
    for (int j = 1; j < n; j++)
        dp[0][j] = t[0] == s[j] ? dp[0][j - 1] + 1 : dp[0][j - 1];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = t[i] == s[j] ? dp[i - 1][j - 1] + dp[i][j - 1] : dp[i][j - 1];

    return dp[m - 1][n - 1];
}