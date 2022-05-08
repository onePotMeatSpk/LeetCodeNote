#pragma once
#include<vector>
using namespace std;

//力扣122
// 题目：买卖股票的最佳时机II_不限买卖次数
// 题目描述：给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
//          在每一天，你可以决定是否购买和 / 或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
//          返回 你能获得的 最大 利润 。

//思路：参考代码随想录题解
//dp[i][j]表示，在第i天的第j中状态下的利润
//dp[i][0]表示手上有股票，有两种情况：
//      1、今天刚买入,dp[i - 1][1] - prices[i],此处和买卖股票第1题不同，第1题只允许买卖一次，所以只要买，就必定是第一次买，故而是-prices[i]，然而这里不限制次数，所以今天买，有可能是在昨天已经卖掉了股票的基础上进行的；
//      2、昨天手上就有股票，传到了今天,dp[i - 1][0]
//dp[i][1]表示手上没有股票，有两种情况：
//      1、今天刚卖出,dp[i - 1][0] + prices[i]；
//      2、昨天手上就没有股票,dp[i - 1][1]


int maxProfit(vector<int>& prices) {
    int m = prices.size();
    vector<vector<int>> dp(m, vector<int>(2, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[m - 1][1];
}