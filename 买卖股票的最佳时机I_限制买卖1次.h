#pragma once
#include<vector>
using namespace std;

//力扣121
// 题目：买卖股票的最佳时机I_限制买卖1次
// 题目描述：给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//          你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//          返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

//思路：参考代码随想录题解
//dp[i][j]表示，在第i天的第j中状态下的利润
// 
//dp[i][0]表示手上有股票，有两种情况：1、今天刚买入,-prices[i]；2、昨天手上就有股票，传到了今天,dp[i - 1][0]
//dp[i][1]表示手上没有股票，有两种情况：1、今天刚卖出,dp[i - 1][0] + prices[i]；2、昨天手上就没有股票,dp[i - 1][1]

int maxProfit(vector<int>& prices) {
    int m = prices.size();
    vector<vector<int>> dp(m, vector<int>(2, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[m - 1][1];
}