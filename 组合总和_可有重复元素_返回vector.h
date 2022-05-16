#pragma once
#include<vector>
using namespace std;

//力扣39
//题目：组合总和_可有重复元素_返回vector
//题目描述：给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和
//			为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//			candidates 中的 同一个 数字可以   无限制重复   被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

//回溯法
void dfsCombinationSum(const vector<int>& candidates, const int& target, vector<int>& v, vector<vector<int>>& vAll, int sum = 0, int index = 0) {
	//得到target，或者到达末尾
	if (sum == target)
	{
		vAll.push_back(v);
		return;
	}
	if (index == candidates.size())	return;

	//以当前元素的不同个数，分叉，进行dfs
	int i = 0;
	for (i = 0; i <= (target - sum) / candidates[index]; i++)//i <= (target - sum) / candidates[index]，防止sum>target
	{
		if(i)	v.push_back(candidates[index]);
		dfsCombinationSum(candidates, target, v, vAll, sum + candidates[index] * i, index + 1);
	}
	//恢复现场
	while (--i)
		v.pop_back();

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> vAll;
	vector<int> v;
	dfsCombinationSum(candidates, target, v, vAll);
	return vAll;
}