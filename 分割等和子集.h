#pragma once
#include<vector>
using namespace std;
//力扣416
//题目：分割等和子集
//题目描述：给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。


//思路：只有数组总和sum为偶数，才可分割。
//      求，在sum/2限制下，所选择的数组元素可达到的最大的元素和，每个元素只能使用1次，最大元素和如果等于sum/2，则true。
//      这个问题就变成了01背包问题，背包容量是sum/2，背包中现有物品价值是子集元素和，物品质量、价值都是数组元素值。
//      求，在背包容量限制下，所装物品可以达到的最大价值，每个物品只能装1次。

//dp,01背包，O(NM),O(NM)，没有进行空间压缩
bool canPartition(vector<int>& nums) {
    int n = nums.size(), w = 0, v;
    for (int i = 0; i < n; i++)  w += nums[i];
    if (w & 1)   return false;
    w >>= 1;
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        v = nums[i - 1];
        for (int j = 1; j <= w; j++)
            if (j >= v)  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v] + v);
            else    dp[i][j] = dp[i - 1][j];
    }
    if (dp[n][w] == w)   return true;
    return false;
}