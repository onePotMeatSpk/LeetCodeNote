#pragma once
#include<iostream>
#include<vector>
using namespace std;

//该函数核心思想是在[left,right]闭区间内进行二分搜索
int missingNumberCore(vector<int>& nums, int left, int right)
{
	if (right < left)	return -1;//说明nums为空
	if (left == right)//left==right是最终要达到的效果
	{
		if (left == nums.size() - 1)//left是数组末尾时，有两种可能
		{
			if (nums[left] > left)	return left;//第一种：缺失的元素是n-2
			if (nums[left] == left)	return left + 1;//第二种：缺失的元素是n-1
		}
		return left;//left不为数组末尾时，left本身就是缺失的元素
	}

	int mid = left + (right - left) / 2;
	if (nums[mid] > mid)	return missingNumberCore(nums, left, mid);//如果mid处元素大于mid，则说明mid左边（含mid处）元素缺失，向左二分查找
	if (nums[mid] == mid)	return missingNumberCore(nums, mid + 1, right);//如果mid处元素等于mid，则说明mid右边（不含mid）处元素缺失，向右二分查找
	return -1;//鲁棒控制：保证所有情况下都有返回值
}

int missingNumber(vector<int>& nums)
{
	return missingNumberCore(nums, 0, nums.size() - 1);
}