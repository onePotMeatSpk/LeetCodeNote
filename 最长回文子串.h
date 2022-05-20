#pragma once
#include<vector>
#include<string>
using namespace std;
//力扣5
//题目：最长回文子串
//题目描述：给你一个字符串 s，找到 s 中最长的回文子串。

//与回文子串（力扣647）相同思路，只不过将回文子串中记录子串数量的num，换成了记录最长长度的maxLen和记录子串开始坐标的start
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