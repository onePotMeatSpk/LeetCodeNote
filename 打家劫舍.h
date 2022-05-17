#pragma once
#include<vector>
using namespace std;

//力扣198
//题目：打家劫舍
//题目描述：相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//			给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

//dp
int rob(vector<int>& nums) {
    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];

    for (int i = 2; i <= nums.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);

    return dp[nums.size()];
}
