#pragma once
#include<vector>
using namespace std;
//题目：最大子数组和
//题目描述：给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//			子数组 是数组中的一个连续部分。


//dp
//类似于最长连续递增序列（力扣674）
int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    vector<int> dp(len, 0);

    dp[0] = nums[0];
    int maxSum = dp[0];
    for (int i = 1; i < len; i++)
    {
        dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        maxSum = maxSum > dp[i] ? maxSum : dp[i];
    }

    return maxSum;
}