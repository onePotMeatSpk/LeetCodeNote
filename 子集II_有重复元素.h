#pragma once
#include<vector>
using namespace std;
//力扣78
//题目：子集II_有重复元素
//题目描述：给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
//          解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。


void back(vector<int>& nums, vector<bool>& used, vector<int>& v, vector<vector<int>>& ret, int index = 0)
{
    ret.push_back(v);
    if (index == nums.size())    return;

    for (; index < nums.size(); index++)
    {
        if (index > 0 && nums[index - 1] == nums[index] && used[index - 1] == 0) continue;

        v.push_back(nums[index]);
        used[index] = 1;
        back(nums, used, v, ret, index + 1);
        used[index] = 0;
        v.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<int> v;
    vector<bool> used(nums.size(), 0);
    vector<vector<int>> ret;

    back(nums, used, v, ret);
    return ret;
}