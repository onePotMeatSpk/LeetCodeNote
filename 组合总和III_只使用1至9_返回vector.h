#pragma once
#include<vector>
#include<algorithm>
using namespace std;

//力扣216
//题目：组合总和III_只使用1至9_返回vector
//题目描述：找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//			只使用数字1到9
//			每个数字 最多使用一次 
//			返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

//回溯
void dfsCombinationSum3(const int& k, const int& n, vector<vector<int>>& vAll, vector<int>& v,int index = 1, int sum = 0, int count = 0) {
	//递归终止
	if (sum == n && count == k)//条件满足
	{
		vAll.push_back(v);
		return;
	}
	if (sum >= n)	return;//sum超了，count不够
	if (count == k)	return;//count够了，sum不够
	if (index == 10)	return;//index超了

	//不用index数字
	dfsCombinationSum3(k, n, vAll, v, index + 1, sum, count);//index + 1, sum不变, count不变
	//使用index数字
	v.push_back(index);//布置现场
	dfsCombinationSum3(k, n, vAll, v, index + 1, sum + index, count + 1);//index + 1, sum + index, count + 1
	v.pop_back();//恢复现场
}


vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> vAll;
	vector<int> v;
	dfsCombinationSum3(k, n, vAll, v);
	return vAll;
}