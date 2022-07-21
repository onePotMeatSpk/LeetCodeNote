#pragma once
#include<vector>
#include<stack>
#include<unordered_map>
#include<iostream>
using namespace std;
//力扣503
//题目：下一个更大元素II
//题目描述：给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。
//			数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 - 1 。



vector<int> nextGreaterElements(vector<int>& nums) {
    int len = nums.size();
    vector<int> ret(len, -1);
    stack<int> s;

    for (int i = 0; i < len * 2; i++)
    {
        while (!s.empty() && nums[i % len] > nums[s.top() % len])
        {
            if (s.top() < len)
                ret[s.top()] = nums[i % len];
            s.pop();
        }
        s.push(i);
    }
    return ret;
}
