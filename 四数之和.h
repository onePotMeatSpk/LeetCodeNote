#pragma once
#include<vector>
#include<algorithm>
using namespace std;

//力扣15
//题目：四数之和 
//题目描述：给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在四个元素 a，b，c, d ，使得 a + b + c + d = 0 ？请你找出所有和为 0 且不重复的四元组。
//          注意：答案中不可以包含重复的四元组。


//该题与力扣15三数之和，同一思路，只不过再多一数字而已，那就在外层再嵌套一层循环，反正最内部用的都是双指针
//类似的题目，无论是几数之和，都可以将最内层的循环换为双指针，以降低一个数量级的复杂度
//排序+双指针，O(N^3),O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	int len = nums.size();
	vector<vector<int>> ret;

	//第一层循环，寻找第一数字
	for (int i = 0; i < len; i++)
	{
		//第一个数字去重
		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		//第二层循环，寻找第二数字
		for (int j = i + 1; j < len; j++)
		{
			//第二个数字去重
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;

			//双指针，寻找第三、四数字
			int l = j + 1, r = len - 1;
			while (l < r)
			{
				//第三个数字去重
				if (l > j + 1 && nums[l] == nums[l - 1])
				{
					l++;
					continue;
				}

				//第四个数字去重
				if (r < len - 1 && nums[r] == nums[r + 1])
				{
					r--;
					continue;
				}

				//使用longlong，防止溢出
				long long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];
				if (sum > target)
					r--;
				else if (sum < target)
					l++;
				else
				{
					ret.push_back({ nums[i], nums[j], nums[l],nums[r] });
					l++;
				}
			}
		}
	}

	return ret;
}