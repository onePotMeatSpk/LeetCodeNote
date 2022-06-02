#pragma once
#include<vector>
using namespace std;
//力扣46
//题目：全排列
//题目描述：给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

//回溯，没啥可说，注意状态修改和状态恢复即可
//递归函数
void back(vector<int>& nums, vector<bool>& used, vector<vector<int>>& ret, vector<int>& v)
{
    if(v.size() == nums.size())
    {
        ret.push_back(v);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (used[i] == 1)    continue;

        used[i] = 1;
        v.push_back(nums[i]);
        back(nums, used, ret, v);
        v.pop_back();
        used[i] = 0;
    }
    
}
//主函数
vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), 0);
    vector<vector<int>> ret;
    vector<int> v;

    back(nums, used, ret, v);
    return ret;
}