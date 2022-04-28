#pragma once
#include<vector>
using namespace std;
//题目：最长递增子序列
//题目描述：给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//			子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
//			例如，[3, 6, 2, 7] 是数组[0, 3, 1, 6, 2, 2, 7] 的子序列。

//思路：dp[i] 可以表示以i 结尾的、最长子序列长度。对于每一个位置i，如果其之前的某个位置j 所对应的数字小于位置i 所对应
//		的数字，则我们可以获得一个以i 结尾的、长度为dp[j]+ 1 的子序列。为了遍历所有情况，我们需要i 和j 进行两层循环，
//		其时间复杂度为O(N^2)。
//dp,O(N^2),O(N)
int lengthOfLIS(vector<int>& nums) {
	int max_length = 0, n = nums.size();
	if (n <= 1) return n;
	vector<int> dp(n, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		max_length = max(max_length, dp[i]);
	}
	return max_length;
}


//优化算法！！！！！！！！！！！
//思路：本题还可以使用二分查找将时间复杂度降低为O(NlogN)。我们定义一个dp 数组，其中dp[k]	
//存储长度为k + 1 的最长递增子序列的最后一个数字。我们遍历每一个位置i，如果其对应的数字
//大于dp 数组中所有数字的值，那么我们把它放在dp 数组尾部，表示最长递增子序列长度加1；
//如果我们发现这个数字在dp 数组中比数字a 大、比数字b 小，则我们将b 更新为此数字，使得
//之后构成递增序列的可能性增大。以这种方式维护的dp 数组永远是递增的，因此可以用二分查
//找加速搜索。

int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	if (n <= 1) return n;
	vector<int> dp;
	dp.push_back(nums[0]);
	for (int i = 1; i < n; ++i) {
		if (dp.back() < nums[i]) {
			dp.push_back(nums[i]);
		}
		else {
			auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
			*itr = nums[i];
		}
	}
	return dp.size();
}
