#pragma once
#include<vector>
#include<string>
using namespace std;
//力扣392
//题目：判断子序列
//题目描述：给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
//          字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
//          （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。


//思路1
//双指针，O（N+M）
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

//思路2
//dp
//转化为最长子序列，如果最长子序列的长度等于s长度，说明是s整体是t的子序列
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