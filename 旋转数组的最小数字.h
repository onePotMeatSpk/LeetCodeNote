#pragma once
#include<vector>
#include<iostream>
using namespace std;
//题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//		给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最
//		小元素。例如，数组 [3, 4, 5, 1, 2] 为[1, 2, 3, 4, 5] 的一次旋转，该数组的最小值为1。

//思路见 https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/
//二分法，时间复杂度O(logN)，空间复杂度O(0)
int minArray(vector<int>& numbers) {
	if (numbers.size() == 1)	return numbers[0];
	int left = 0, right = numbers.size() - 1, mid;
	while (left != right)
	{
		mid = left + (right - left) / 2;
		if (numbers[mid] < numbers[right])
		{
			right = mid;
			continue;
		}

		if (numbers[mid] > numbers[right])
		{
			left = mid + 1;
			continue;
		}

		if (numbers[mid] == numbers[right])
		{
			right--;;
			continue;
		}
	}

	return numbers[left];
}