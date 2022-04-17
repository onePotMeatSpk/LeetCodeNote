#pragma once
#include<vector>
using namespace std;
//题目：全排列
//题目描述：给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

//回溯，没啥可说，注意状态修改和状态恢复即可
//递归函数
void permuteCore(vector<int>& nums, vector<bool>& used, vector<vector<int>>& vAll, vector<int>& v)
{
    if(v.size() == nums.size())
    {
        vAll.push_back(v);
        return;
    }

    for(int i = 0; i < nums.size(); i++)
        if(used[i] == false)
        {
            used[i] = true;
            v.push_back(nums[i]);
            permuteCore(nums, used, vAll, v);
            v.pop_back();
            used[i] = false;
        }
}
//主函数
vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    vector<vector<int>> vAll;
    vector<int> v;
    permuteCore(nums, used, vAll, v);
    return vAll;
}