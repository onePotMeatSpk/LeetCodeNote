#pragma once
#include<vector>
using namespace std;

//力扣322
//题目：零钱兑换
//题目描述：给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//			计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回  - 1 。
//			你可以认为每种硬币的数量是无限的。

//dp[j]，表示在钱包正好装到j元的情况下，最少有几个硬币。dp[j]为INT_MAX，表示钱包无法被正好装到j元。
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++) { // 遍历物品
        for (int j = coins[i]; j <= amount; j++) { // 遍历背包

            // 因为dp[j - coins[i]]是INT_MAX,说明钱包无法被装到j - coins[i]元，
            //又因为j - coins[i]元只需加上一个coins[i]元就是j元
            //所以在必须使用当前硬币的情况下，钱包无法被装到j元
            //所以不使用当前硬币，dp[j] = dp[j]不变，也就是直接使用只用前面的硬币把钱包正好装到j元的数量
            if (dp[j - coins[i]] != INT_MAX) { 
                //钱包被装到j元，有两种方式：
                // 1：装当前硬币，在装到j - coins[i]元的基础上加1个当前硬币
                // 2：不装当前硬币，当前数量就是，只用前面的硬币把钱包正好装到j元的数量
                //取两者的最小者即可
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
    }
    if (dp[amount] == INT_MAX) return -1;
    return dp[amount];
}
