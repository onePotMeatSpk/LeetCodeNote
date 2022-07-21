#pragma once
#include<vector>
#include<algorithm>
using namespace std;
//力扣698
//题目：划分为k个相等的子集
//题目描述：给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。


//回溯
bool back(vector<int>& nums, vector<bool>& used, int k, int& sum, int need, int index = 0)
{
    if (k == 0)
        return true;

    for (int i = index; i < nums.size() && nums[i] <= need; i++)
    {
        if (used[i] == 1)
            continue;

        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
            continue;

        used[i] = 1;
        if (nums[i] == need)
        {
            //每当填满一个子集，就从首位开始，填下一个子集
            if (back(nums, used, k - 1, sum, sum, 0))
                return true;
        }
        else
            //当该子集没有填满，就从下一位开始，继续填当前子集
            if (back(nums, used, k, sum, need - nums[i], index + 1))
                return true;
        used[i] = 0;
    }

    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (int i : nums)
        sum += i;

    //除尽
    if (sum % k != 0)
        return false;

    sum = sum / k;
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), 0);
    //回溯
    return back(nums, used, k, sum, sum);
}