#pragma once
#include<vector>
#include<iostream>
using namespace std;
//题目：在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
//		也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

//哈希表，时间复杂度O(N),空间复杂度O(N)
//int findRepeatNumber(vector<int>& nums) {
//	vector<int> hashtable(nums.size());
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (hashtable[nums[i]] != 0)
//			return nums[i];
//		else
//			hashtable[nums[i]]++;
//	}
//	return -1;
//}

//原地哈希，时间复杂度O(N)，空间复杂度O(0)
//思想：尽量让nums[i]等于i，一个萝卜一个坑，多出来的萝卜就是重复的数字
int findRepeatNumber(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++)
	{
		while (nums[i] != i)
		{
			if (nums[i] == nums[nums[i]])
				return nums[i];
			else
				swap(nums[i], nums[nums[i]]);
		}
	}
	return -1;
}
