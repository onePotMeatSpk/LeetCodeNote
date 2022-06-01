#pragma once
#include<vector>
using namespace std;
//力扣78
//题目：子集
//题目描述：给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//			解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

//回溯函数：求长度为need的子集
void back(vector<int>& nums, vector<int>& v, vector<vector<int>>& ret, int need, int index = 0)
{
    if (need == 0)
    {
        ret.push_back(v);
        return;
    }
    if (index == nums.size())    return;

    for (; index < nums.size(); index++)
    {
        v.push_back(nums[index]);
        back(nums, v, ret, need - 1, index + 1);
        v.pop_back();
    }
}

//主函数
vector<vector<int>> subsets(vector<int>& nums) {
    //任何集合都有空子集
    vector<vector<int>> ret;
    ret.push_back({});
    if (nums.empty())    return ret;


    vector<int> v;
    //长度从1到nums.size()，按不同长度，分别求子集
    for (int i = 1; i <= nums.size(); i++)
        back(nums, v, ret, i);
    return ret;
}