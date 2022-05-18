#pragma once
#include<vector>
using namespace std;
//力扣674
//题目：最长连续递增序列
//题目描述：给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
//			连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
//			那么子序列[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

//dp
//dp[i]代表，以i结尾的子数组，如果是一个递增数组，那么其最大长度是多少
//dp[i] = nums[i] > nums[i - 1] ? dp[i - 1] + 1 : 1：
//          nums[i] > nums[i - 1] ：i-1、i可以组成连续递增子数组，该子数组能不能更长，取决于以i-1结尾的连续递增子数组的最大长度dp[i - 1]
//          nums[i] <= nums[i - 1]：i-1、i不能组成连续递增子数组，那么必须从i开始，重新建立一个连续递增子数组，i既是头也是尾，dp[i]=1
int findLengthOfLCIS(vector<int>& nums) {
    int len = nums.size();
    vector<int> dp(len, 1);

    int maxLen = 1;
    for (int i = 1; i < len; i++)
    {
        dp[i] = nums[i] > nums[i - 1] ? dp[i - 1] + 1 : 1;
        maxLen = maxLen > dp[i] ? maxLen : dp[i];
    }

    return maxLen;
}