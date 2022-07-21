#pragma once
#include<vector>
using namespace std;

//力扣213
//题目：打家劫舍II_环形小区
//题目描述：这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
//          同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//          给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。


//dp
//数组成环之后，有三种情况：
//  1、不考虑偷头、尾
//  2、不考虑偷尾
//  3、不考虑偷头
//其中，1被2、3包含，所以只需要考虑2、3即可。
int help(vector<int>& nums, int start, int end)
{
    vector<int> dp(end - start + 2, 0);
    dp[0] = 0;
    dp[1] = nums[start];

    for (int i = 2; i < dp.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i - 1]);

    return dp[dp.size() - 1];
}
int rob(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];

    //不考虑偷尾部     
    int ret0 = help(nums, 0, nums.size() - 2);
    //不考虑偷头部
    int ret1 = help(nums, 1, nums.size() - 1);

    return max(ret0, ret1);
}