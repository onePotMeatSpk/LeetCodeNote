#pragma once
#include<vector>
using namespace std;

//力扣309
// 题目：买卖股票的最佳时机V_冷静期
// 题目描述：给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
//			设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
//			卖出股票后，你无法在第二天买入股票(即冷冻期为 1 天)。
//			注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

//思路：参考代码随想录题解
//dp[i][j]表示，在第i天的第j中状态下的利润
//有四种状态：持股票期dp[i][0]、卖股票日dp[i][1]、冷静期dp[i][2]、无股票期dp[i][3]
//状态之间可以这样转换：持股票期->持股票期、冷静期->持股票期、无股票期->持股票期
//						持股票期->卖股票日
//						卖股票日->冷静期
//						冷静期->无股票期

int maxProfit(vector<int>& prices) {
    int m = prices.size();
    vector<vector<int>> dp(m, vector<int>(4, 0));
    dp[0][0] = -prices[0];

    for (int i = 1; i < m; i++)
    {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3]) - prices[i]);
        dp[i][1] = dp[i - 1][0] + prices[i];
        dp[i][2] = dp[i - 1][1];
        dp[i][3] = max(dp[i - 1][2], dp[i - 1][3]);
    }

    return max(max(dp[m - 1][1], dp[m - 1][2]), dp[m - 1][3]);
}