﻿#pragma once
#include<vector>
using namespace std;

//力扣123
// 题目：买卖股票的最佳时机III_限制买卖2次
// 题目描述：给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
//          设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
//          注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。


//思路：参考代码随想录题解
//dp[i][j]表示，在第i天的第j中状态下的利润
//dp[i][0]表示一次股票都没有买卖过，利润自然是0
//dp[i][1]表示手上有第1次买入的股票，有两种情况：
//      1、在昨天手上没有任何股票的基础上，今天刚买入的1次股票,dp[i - 1][0] - prices[i]；
//      2、昨天手上就有股票，传到了今天,dp[i - 1][1]
//dp[i][2]表示卖出了第1次买入的股票，且现在手上没有股票，有两种情况：
//      1、今天刚卖出,dp[i - 1][1] + prices[i]；
//      2、昨天手上就没有股票,也就是说在昨天或之前第1次股票就已经卖出了，dp[i - 1][2]
//dp[i][3]表示手上有第2次买入的股票，有两种情况：
//      1、在第1次股票已经在昨天或之前卖掉了的基础上，今天刚买入第2次股票,dp[i - 1][2] - prices[i]；
//      2、昨天手上就有股票，传到了今天,dp[i - 1][3]
//dp[i][4]表示卖出了第2次买入的股票，且现在手上没有股票，有两种情况：
//      1、今天刚卖出,dp[i - 1][3] + prices[i]；
//      2、昨天手上就没有股票,也就是说在昨天或之前第2次股票就已经卖出了，dp[i - 1][4]
int maxProfit(vector<int>& prices) {
    int m = prices.size();
    vector<vector<int>> dp(m, vector<int>(5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < m; i++)
    {
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    //不一定非得进行2次买卖，有可能仅进行1次买卖，利润就达到了最大
    return max(dp[m - 1][2], dp[m - 1][4]);
}