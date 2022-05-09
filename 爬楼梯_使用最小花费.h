#pragma once
#include<vector>
using namespace std;

//力扣746
//题目：爬楼梯_使用最小花费
//题目描述：给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//			你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//			请你计算并返回达到楼梯顶部的最低花费。

//dp
int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size() + 1, 0);
    for (int i = 2; i < cost.size() + 1; i++)
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);

    return dp[cost.size()];
}
