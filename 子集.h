#pragma once
#include<vector>
using namespace std;
//力扣78
//题目：子集
//题目描述：给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//			解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

//子集问题：参见代码随想录

//回溯
void back(vector<int>& nums, vector<int>& v, vector<vector<int>>& ret, int index = 0)
{
    ret.push_back(v);//子集问题中，子集添加这一操作，不能在递归终止条件之中，应该在之前
                     //如果在之中，就会导致，只有到达了末尾的子集，才能被添加
                     //而很多子集，是不包含末尾元素的，所以必须走一步就添加一次，这样才能保证所有子集均被添加
    if (index == nums.size())    return;

    for (; index < nums.size(); index++)
    {
        v.push_back(nums[index]);
        back(nums, v, ret, index + 1);
        v.pop_back();
    }
}

//主函数
vector<vector<int>> subsets(vector<int>& nums) {
    //任何集合都有空子集
    vector<vector<int>> ret;
    vector<int> v;

    back(nums, v, ret);
    return ret;
}