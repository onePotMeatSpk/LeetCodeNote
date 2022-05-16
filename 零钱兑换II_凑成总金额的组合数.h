#pragma once
#include<vector>
using namespace std;
//力扣518
//题目：零钱兑换II_凑成总金额的组合数
//题目描述：给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
//			请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
//			假设每一种面额的硬币有无限个。 

//求组合总数的经典问题，完全背包
//dp[j]表示金额j的组合总数
// dp[j] += dp[j - coins[i]]
//dp[0]=1,组合总数的经典操作，因为所有方法最终都要落到dp[0]，所以必须为1
int change(int amount, vector<int>& coins) {
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < coins.size(); i++)
		for (int j = coins[i]; j <= amount; j++)
			dp[j] += dp[j - coins[i]];
	return dp[amount];
}