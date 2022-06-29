#pragma once
#include<vector>
using namespace std;
//力扣34
//题目：在排序数组中查找元素的第一个和最后一个位置
//题目描述：给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
			//如果数组中不存在目标值 target，返回 [-1, -1]。
			//你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。


//二分法，左闭右闭，动用两次二分法，分别来找两个边界
//mid掉落在两边界之外时，两次二分的逻辑相同，都是往边界里面靠近
//mid掉落在两边界之内时，找左边界的逻辑，是尽量往左边靠，找右边界的逻辑，是尽量往右边靠
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ret(2, -1);

    //先找左边界
    int l = 0, r = nums.size() - 1, mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] < target)
            l = mid + 1;
        else if (nums[mid] > target)
            r = mid - 1;
        else
            if (mid - 1 == -1 || nums[mid - 1] < nums[mid])
            {
                ret[0] = mid;
                break;
            }
            else
                r = mid - 1;
    }

    //再找右边界
    l = 0, r = nums.size() - 1, mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] < target)
            l = mid + 1;
        else if (nums[mid] > target)
            r = mid - 1;
        else
            if (mid + 1 == nums.size() || nums[mid + 1] > nums[mid])
            {
                ret[1] = mid;
                break;
            }
            else
                l = mid + 1;
    }

    return ret;
}