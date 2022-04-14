#pragma once
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> vecetorOfTwoNums;
	if (nums.empty())	return vecetorOfTwoNums;
	if (nums.size() == 1) return vecetorOfTwoNums;

	int i = 0, j = nums.size() - 1;
	while (i < j)
	{
		if (nums[i] + nums[j] < target)
		{
			i++;
			continue;
		}

	}
	return vecetorOfTwoNums;


}