#pragma once
#include<vector>
using namespace std;
//力扣714
// 题目：买卖股票的最佳时机VI_不限买卖次数_含手续费
// 题目描述：给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
//          你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
//          返回获得利润的最大值。

//思路：在买卖股票的最佳时机II_不限买卖次数基础上，在卖股票的时候减去手续费即可
//dp[i][j]表示，在第i天的第j中状态下的利润
//dp[i][0]表示手上有股票，有两种情况：
//      1、今天刚买入,dp[i - 1][1] - prices[i]；
//      2、昨天手上就有股票，传到了今天,dp[i - 1][0]
//dp[i][1]表示手上没有股票，有两种情况：
//      1、今天刚卖出,dp[i - 1][0] + prices[i] - fee；
//      2、昨天手上就没有股票,dp[i - 1][1]


int maxProfit(vector<int>& prices, int fee) {
    int m = prices.size();
    vector<vector<int>> dp(m, vector<int>(2, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return dp[m - 1][1];
}