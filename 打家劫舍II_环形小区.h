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
//  1、不考虑头、尾
//  2、考虑头，不考虑尾
//  3、不考虑头，考虑尾
//其中，1被2、3包含，所以只需要考虑2、3即可。
int rob(vector<int>& nums) {
    int len = nums.size();
    if (len == 0)   return 0;
    if (len == 1)   return nums[0];
    if (len == 2)   return max(nums[0], nums[1]);;
    
    vector<int> dp(len, 0);

    //  2、考虑头，不考虑尾
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < len - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    int money = dp[len - 2];

    //  3、不考虑头，考虑尾
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for (int i = 3; i < len; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    money = money > dp[len - 1] ? money : dp[len - 1];

    return money;
}