#pragma once
#include<vector>
using namespace std;
//题目：等差数列数量
//题目描述：如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。
//		例如，[1, 3, 5, 7, 9]、[7, 7, 7, 7] 和[3, -1, -5, -9] 都是等差数列。
//		给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。
//		子数组 是数组中的一个连续序列。


//思想，数组长度每加一，等差数列的数量是随规律变化的：1+2+3+…
//动态规划，O(N),0(1)
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
        return 0;
    }
    int d = nums[0] - nums[1], t = 0;//d是差值，t是数量计数
    int ans = 0;//ans是等差数列总数记录

    // 因为等差数列的长度至少为 3，所以可以从 i=2 开始枚举
    for (int i = 2; i < n; ++i) {
        if (nums[i - 1] - nums[i] == d) {//当前数字延续了前面的等差数列
            ++t;//遵循上述规律
        }
        else {//当前数字打破了前面的等差数列
            d = nums[i - 1] - nums[i];//更新新差值
            t = 0;//新的等差数列开始，t重置
        }
        ans += t;//统计新数量
    }
    return ans;
}