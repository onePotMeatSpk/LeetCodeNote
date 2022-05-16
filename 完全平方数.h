#pragma once
#include<vector>
using namespace std;
//力扣279
//题目：完全平方数
//题目描述：给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
//		完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。


//完全背包
//dp[j]：和为j的完全平方数的最少数量
// dp[0] = 0，和为0自然数量是0
//dp[j] = min(dp[j], dp[j - i * i] + 1)：有两种方法使得和为j，使用、不使用i*i
int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i * i <= n; i++)
        for (int j = i * i; j <= n; j++)
            dp[j] = min(dp[j], dp[j - i * i] + 1);

    return dp[n];
}
