#pragma once
#include<vector>
using namespace std;
//力扣35
//题目：搜索插入位置
//题目描述：给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
            //请必须使用时间复杂度为 O(log n) 的算法。

//二分法，左闭右闭
int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, mid = 0;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }

    //没找到target的话，由于mid是最靠近target的值，插入点肯定在mid旁边
    //nums[mid] > target的话，那就插在 mid处，让原本mid的值往后挪
    //nums[mid] < target的话，那就插在 mid + 1处
    if (nums[mid] > target)
        return mid;
    else
        return mid + 1;
}