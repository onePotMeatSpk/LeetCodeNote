#pragma once
#include<vector>
#include<string>
using namespace std;
//力扣516
//题目：最长回文子序列
//题目描述：给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
			//子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

//dp
//与最长回文子串（力扣5）相同思路
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