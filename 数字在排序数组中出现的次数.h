#pragma once
#include"单向链表.h"
using namespace std;

//确定target首次与末次出现的位置的函数（二分法）
//返回值为1说明数组中有target，为0说明没有
int searchCore(vector<int>& nums, int target, int left, int right, int& indexOfFirstTarget, int& indexOfLastTarget)
{
	/*
	这个算法的核心思想在于，利用二分法来查找
	如果mid处元素不等于target，则根据大小关系向两边查找
	如果mid处元素等于target，则根据一个中心法则：mid左边元素小于mid处元素则说明mid是target首次出现位置，mid右边元素大于mid处元素则说明mid是target末次出现位置
	*/

	if (left > right)//数组已经按照二分法遍历完毕
	{
		if ((indexOfFirstTarget == -1) && (indexOfLastTarget == -1))	return 0;//如果两个位置参数仍为初始值，说明数组中没找到target
		return 1;
	}
	int mid = left + (right - left) / 2;
	if (nums[mid] < target)	return searchCore(nums, target, mid + 1, right, indexOfFirstTarget, indexOfLastTarget);//mid处元素小于target，则向后二分查找
	if (nums[mid] > target)	return searchCore(nums, target, left, mid - 1, indexOfFirstTarget, indexOfLastTarget);//mid处元素大于target，则向前二分查找
	//下面是mid处元素等于target的情况
	if (mid == 0)//若mid位于数组左边界
	{
		if (nums[mid + 1] > target)
		{
			indexOfFirstTarget = mid;
			indexOfLastTarget = mid;
			return 1;
		}
		if (nums[mid + 1] == target)
		{
			indexOfFirstTarget = mid;
			return searchCore(nums, target, mid + 1, right, indexOfFirstTarget, indexOfLastTarget);
		}
	}
	if (mid == nums.size() - 1)//若mid位于数组右边界
	{
		if (nums[mid - 1] < target)
		{
			indexOfFirstTarget = mid;
			indexOfLastTarget = mid;
			return 1;
		}
		if (nums[mid - 1] == target)
		{
			indexOfLastTarget = mid;
			return searchCore(nums, target, left, mid - 1, indexOfFirstTarget, indexOfLastTarget);
		}
	}
	//下面是mid位于数组中间的情况
	if ((nums[mid - 1] < target) && (nums[mid + 1] > target))
	{
		indexOfFirstTarget = mid;
		indexOfLastTarget = mid;
		return 1;
	}
	if ((nums[mid - 1] < target) && (nums[mid + 1] == target))
	{
		indexOfFirstTarget = mid;
		return searchCore(nums, target, mid + 1, right, indexOfFirstTarget, indexOfLastTarget);
	}
	if ((nums[mid - 1] == target) && (nums[mid + 1] > target))
	{
		indexOfLastTarget = mid;
		return searchCore(nums, target, left, mid - 1, indexOfFirstTarget, indexOfLastTarget);
	}
	if ((nums[mid - 1] == target) && (nums[mid + 1] == target))
	{
		searchCore(nums, target, mid + 1, right, indexOfFirstTarget, indexOfLastTarget);
		return searchCore(nums, target, left, mid - 1, indexOfFirstTarget, indexOfLastTarget);
	}
	return 0;
}
int search(vector<int>& nums, int target) {
	if (nums.empty())	return 0;
	if ((nums.size() == 1) && (nums[0] == target))	return 1;
	if ((nums.size() == 1) && (nums[0] != target))	return 0;
	int indexOfFirstTarget = -1, indexOfLastTarget = -1;
	if(searchCore(nums, target, 0, nums.size() - 1, indexOfFirstTarget, indexOfLastTarget))	return indexOfLastTarget - indexOfFirstTarget + 1;
	return 0;
}