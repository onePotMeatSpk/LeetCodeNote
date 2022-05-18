#pragma once
#include<vector>
using namespace std;
//力扣718
//题目：最长重复子数组
//题目描述：给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。

//dp
//思路来自于最长连续递增序列（力扣674）
//dp[i][j]：num1以i结尾，num2以j结尾，他们中有以i、j结尾的两个子数组，
//          dp[i][j]记录这两个子数组是否“公共”，若“公共”，则dp[i][j]是公共子数组的最大长度，若不“公共”，则dp[i][j]是0
//dp[i][j] = nums1[i] == nums2[j] ? dp[i - 1][j - 1] + 1 : 0：
//          i、j元素相等：公共子数组的长度至少为1，至于能不能更长，取决于以i-1、j-1结尾的子数组是否公共子数组，其长度是多少
//          i、j元素不等：这两个子数组肯定不是公共子数组，既然不“公共”，那么代表“公共子数组”长度的dp[i][j]自然是0
//
int findLength(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxLen = 0;
    for (int j = 0; j < n; j++)
        if (nums2[j] == nums1[0])
        {
            dp[0][j] = 1;
            maxLen = 1;
        }

    for (int i = 0; i < m; i++)
        if (nums1[i] == nums2[0])
        {
            dp[i][0] = 1;
            maxLen = 1;
        }

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = nums1[i] == nums2[j] ? dp[i - 1][j - 1] + 1 : 0;
            maxLen = maxLen > dp[i][j] ? maxLen : dp[i][j];
        }
    return maxLen;
}

