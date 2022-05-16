﻿#pragma once
#include<vector>
#include<string>
using namespace std;
//力扣91
//题目:数字字符串解码方法总数
//题目描述：一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
//'A' -> "1"
//'B' -> "2"
//...
//'Z' -> "26"
//要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
//"AAJF" ，将消息分组为(1 1 10 6)
//"KJF" ，将消息分组为(11 10 6)
//
//注意，消息不能分组为 (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。
//给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。
//题目数据保证答案肯定是一个 32 位 的整数。



//dp
int numDecodings(string s) {
    int len = s.size();
    vector<int> dp(len, 0);
    if (s[0] == '0') return 0;
    dp[0] = 1;

    for (int i = 1; i < len; i++)
    {
        if(s[i] != '0')    dp[i] = dp[i - 1];
        int a = atoi(s.substr(i - 1, 2).c_str());
        if (a > 9 && a < 27)    dp[i] += (i > 1 ? dp[i - 2] : 1);
        if (a == 0)  return 0;
            
    }

    return dp[len - 1];
}