#pragma once
#include<vector>
#include<algorithm>
using namespace std;

//力扣377
//题目：组合总和IV_不同排列的总数量_返回int
//题目描述：给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
//			题目数据保证答案符合 32 位整数范围。
//			请注意，顺序不同的序列被视作不同的组合。

//完全背包，因为一个数字可以使用多次
//dp[j]：和为j时的方法总数
//dp[0] = 1，背包解决方法总数类型问题的套路，因为所有的方法最后都要落到dp[0]
//dp[j] += dp[j - nums[i]]，有两种方法使得和j，分别为使用和不使用nums[i]
//先物品后背包为组合，先背包后物品为排列
//顺序不同的序列被视作不同的组合,所以该题使用排列
int combinationSum4(vector<int>& nums, int target) {
	vector<int> dp(target + 1, 0);
	dp[0] = 1;

	//先背包，后物品
	for (int j = 1; j <= target; j++)
		for (int i = 0; i < nums.size(); i++)
			if(j >= nums[i])	dp[j] += dp[j - nums[i]];

	return dp[target];
}
