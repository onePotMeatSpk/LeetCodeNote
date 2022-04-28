﻿#pragma once
#include<vector>
#include<string>
using namespace std;
//题目：最长公共子序列
//题目描述：给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
//			一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
//			例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
//			两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

//思路：
//      dp[i][j]：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
//      主要就是两大情况：text1[i - 1] 与 text2[j - 1]相同，text1[i - 1] 与 text2[j - 1]不相同
//                        如果text1[i - 1] 与 text2[j - 1]相同，那么找到了一个公共元素
//                        即：dp[i][j] = dp[i - 1][j - 1] + 1;
//                        如果text1[i - 1] 与 text2[j - 1]不相同，那就看看text1[0, i - 2]与text2[0, j - 1]的最长公共子序列 和 text1[0, i - 1]与text2[0, j - 2]的最长公共子序列，取最大的。
//                        即：dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//dp，O(MN),O(MN)
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
            dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m][n];
}