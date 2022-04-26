#pragma once
#include<vector>
using namespace std;
//题目：完全平方数
//题目描述：给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
//		完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

//思路：对于分割类型题，动态规划的状态转移方程通常并不依赖相邻的位置，而是依赖于满足分割
//       条件的位置。我们定义一个一维矩阵dp，其中dp[i] 表示数字i 最少可以由几个完全平方数相加
//       构成。在本题中，位置i 只依赖i - k2 的位置，如i - 1、i - 4、i - 9 等等，才能满足完全平方分割
//       的条件。因此dp[i] 可以取的最小值即为1 + min(dp[i - 1], dp[i - 4], dp[i - 9]，…)。

//dp
int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; i - j * j >= 0; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    return dp[n];
}
