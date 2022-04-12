#pragma once
#include<vector>
using namespace std;

//题目：数组中的第K个最大元素
//题目描述：数组中的第K个最大元素
//思路：快选

//随机快选函数
int randomizedPartition(vector<int>& nums, int l, int r)
{
    swap(nums[l], nums[rand() % (r - l + 1) + l]);//partition之前打乱数组，以防O(N^2)
    return partition(nums, l, r);
}

//快选函数
int partition(vector<int>& nums, int l, int r)
{
    int key = l;
    while (l < r)
    {
        while ((l < r) && (nums[r] >= nums[key]))  r--;
        while ((l < r) && (nums[l] <= nums[key]))  l++;
        swap(nums[l], nums[r]);
    }
    swap(nums[key], nums[l]);
    return l;
}

//主函数
int findKthLargest(vector<int>& nums, int k) {
    if (k > nums.size()) return -1;
    int l = 0, r = nums.size() - 1, mid;
    while (true)
    {
        mid = randomizedPartition(nums, l, r);
        if (mid == nums.size() - k)  return nums[mid];
        else if (mid < nums.size() - k)  l = mid + 1;
        else    r = mid - 1;
    }
    return 0;
}