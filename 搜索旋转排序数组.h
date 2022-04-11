#pragma once
#include<vector>
//题目：搜索旋转排序数组
// 题目描述：已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。
//在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]（下标 从 0 开始 计数）。例如，[0, 1, 2, 4, 4, 4, 5, 6, 6, 7] 在下标 5 处经旋转后可能变为[4, 5, 6, 6, 7, 0, 1, 2, 4, 4] 。
//给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。
using namespace std;

bool searchInRotatedArray(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] == target) return 1;//target找到了
        if (nums[mid] == nums[l])    l += 1;//中间值等于左边值，则没办法判断哪边递增，将l右移一位再做判断
        else if (nums[mid] > nums[r])//左边递增
        {
            if (target >= nums[l] && target <= nums[mid])    r = mid - 1;//target在左边
            else    l = mid + 1;//target在右边
        }
        else if (nums[mid] <= nums[r])//右边递增
        {
            if (target >= nums[mid] && target <= nums[r])    l = mid + 1;//target在右边
            else    r = mid - 1;//target在左边
        }
    }
    return 0;//没有找到target
}