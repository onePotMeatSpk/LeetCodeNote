﻿#pragma once
#include<vector>
#include<stack>
#include<unordered_map>
#include<iostream>
using namespace std;
//力扣739
//题目：下一个更大元素 I
//题目描述：nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
			//给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
			//对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 - 1 。
			//返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret1(nums1.size(), -1);
    unordered_map<int, int> umap;
    stack<int> s;

    for (int i = 0; i < nums2.size(); i++)
    {
        while (!s.empty() && nums2[i] > nums2[s.top()])
        {
            umap[nums2[s.top()]] = nums2[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < ret1.size(); i++)
        if (umap.find(nums1[i]) != umap.end())
            ret1[i] = umap[nums1[i]];

    return ret1;
}