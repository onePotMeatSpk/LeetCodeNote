#pragma once
#include<vector>
using namespace std;
//力扣209
//题目：长度最小的子数组
//题目描述：给定一个含有 n 个正整数的数组和一个正整数 target 。
            //找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl + 1, ..., numsr - 1, numsr] ，并返回其长度。
            //如果不存在符合条件的子数组，返回 0 。



//滑动窗口
//在本题中实现滑动窗口，主要确定如下三点：
//
//窗口内是什么？ 窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组。
//
//如何移动窗口的起始位置？ 窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。
//
//如何移动窗口的结束位置？ 窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，窗口的起始位置设置为数组的起始位置就可以了。


int minSubArrayLen(int target, vector<int>& nums) {
    int i = 0, j = 0, sum = 0, minLen = INT_MAX;

    for (j = 0; j < nums.size(); j++)//sum < target时，移动窗口的结束位置（增大窗口）
    {
        sum += nums[j];
        while (sum >= target)//sum >= target时
        {
            int len = j - i + 1;
            minLen = minLen < len ? minLen : len;//更新minLen
            sum -= nums[i++];//移动窗口的开始位置（减小窗口）
        }
    }

    return minLen == INT_MAX ? 0 : minLen;//若minLen仍为INT_MAX，说明没有找到大于等于target的数组
}