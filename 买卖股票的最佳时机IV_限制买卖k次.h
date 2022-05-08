#pragma once
#include<vector>
using namespace std;

//力扣188
// 题目：买卖股票的最佳时机IV_限制买卖k次
// 题目描述：给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
//			设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
//			注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。



//思路：参考代码随想录题解
//dp[i][j]表示，在第i天的第j中状态下的利润
//dp[i][0]表示一次股票都没有买卖过，利润自然是0
//dp[i][奇数j]表示手上有股票，有两种情况：
//      1、在昨天手上没有股票的基础上，今天刚买入的股票,dp[i - 1][j - 1] - prices[i]；
//      2、昨天手上就有股票，传到了今天,dp[i - 1][j]
//dp[i][偶数j]表示卖出了第若干次买入的股票，且现在手上没有股票，有两种情况：
//      1、今天刚卖出股票,dp[i - 1][j - 1] + prices[i]；
//      2、昨天手上就没有股票,也就是说在昨天或之前第若干次股票就已经卖出了，dp[i - 1][j]

int maxProfit(int k, vector<int>& prices) {
    if (!prices.size() || !k)  return 0;
    int m = prices.size(), n = 2 * k + 1;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int j = 1; j < n; j += 2)   dp[0][j] = -prices[0];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (j & 1)   dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
            else    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);

    //不一定非得进行k次买卖，有可能进行了少于k次买卖后，利润就已经达到了最大
    int maxPro = 0;
    for (int j = 2; j < n; j += 2)
        maxPro = maxPro > dp[m - 1][j] ? maxPro : dp[m - 1][j];
    return maxPro;
}