#pragma once
#include<unordered_map>
#include<vector>
using namespace std;
//力扣454
//题目：四数相加II
//题干：给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
        //0 <= i, j, k, l < n
        //nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

//思路
//首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
//遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
//定义int变量count，用来统计 a + b + c + d = 0 出现的次数。
//在遍历大C和大D数组，找到如果 0 - (c + d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
//最后返回统计值 count 就可以了
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> umap;

    for (int i = 0; i < nums1.size(); i++)
        for (int j = 0; j < nums2.size(); j++)
            umap[nums1[i] + nums2[j]]++;

    int ret = 0;
    for (int i = 0; i < nums3.size(); i++)
        for (int j = 0; j < nums4.size(); j++)
            ret += umap[-(nums3[i] + nums4[j])];

    return ret;
}