#pragma once
#include<vector>
using namespace std;
//力扣26
//题目：删除有序数组中的重复项
//题目描述：给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。


//二分法
//与力扣27移除元素思路相同（只不过快指针的搜索目标，不再是特定数字，而是与前方数字不同的数字（是新的不重复数字））
int removeDuplicates(vector<int>& nums) {
    if (nums.empty())
        return 0;

    int l = 1, r = 1;

    while (r < nums.size())
    {
        if (nums[r] == nums[r - 1])
            r++;
        else
            nums[l++] = nums[r++];
    }

    return l;
}
