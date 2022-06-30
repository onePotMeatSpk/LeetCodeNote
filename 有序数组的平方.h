#pragma once
#include<vector>
using namespace std;
//力扣977
//题目：有序数组的平方
//题目描述：给你一个按 非递减顺序 排序的整数数组 nums，返回  每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

//先找出绝对值最小的基准点base，则base左右的绝对值都大于base
//再从base开始，分别向左右求取平方，并记录即可，类似归并排序中的归并
vector<int> sortedSquares(vector<int>& nums) {

    //找出绝对值最小的点
    int base = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (abs(nums[i]) <= abs(nums[base]))
            base = i;
        else
            break;
    }

    //归并平方
    vector<int> ret;
    int l = base, r = base + 1;
    while (l >= 0 && r < nums.size())
    {
        if (abs(nums[l]) < abs(nums[r]))
        {
            ret.push_back(nums[l] * nums[l]);
            l--;
        }
        else
        {
            ret.push_back(nums[r] * nums[r]);
            r++;
        }
    }

    while (l >= 0)
    {
        ret.push_back(nums[l] * nums[l]);
        l--;
    }

    while (r < nums.size())
    {

        ret.push_back(nums[r] * nums[r]);
        r++;
    }

    return ret;
}