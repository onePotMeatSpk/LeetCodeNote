#pragma once
#include<vector>
using namespace std;
//题目：旋转排序数组中的最小值
//题目描述：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//		给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最
//		小元素。例如，数组 [3, 4, 5, 1, 2] 为[1, 2, 3, 4, 5] 的一次旋转，该数组的最小值为1。


int findMinInRotatedArray(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (r - l == 1)  return min(nums[l], nums[r]);//只剩两个元素，返回最小的(这里有两种情况，一是横跨左右区间边界，二是处在右区间最左侧)
        if (nums[mid] == nums[l])    l += 1;//无法分辨递增区间在左或右
        else if (nums[mid] > nums[r])    l = mid + 1;//递增区间在左，则最小值一定在右
        else if (nums[mid] <= nums[r])   r = mid;//递增区间在右，则最小值一定在左，(这里不应该为r=mid-1，因为有可能导致越界到左区间，就错过了最小值)
    }
    return nums[l];//当只剩最后一个元素时，直接返回即可
}