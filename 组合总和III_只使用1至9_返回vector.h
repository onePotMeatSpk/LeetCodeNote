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
//k：需要的剩余数字个数（剪枝）
//index：开始遍历的坐标
//sum：已达到的和
void back(int k, const int& n, int index, vector<int>& v, vector<vector<int>>& ret, int& sum)
{
    if (sum == n && k == 0)
    {
        ret.push_back(v);
        return;
    }
    if (sum >= n)    return;
    if (k > 9 - index + 1)   return;

    for (; index <= 9; index++)
    {
        v.push_back(index);
        sum += index;
        back(k - 1, n, index + 1, v, ret, sum);
        sum -= index;
        v.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    int sum = 0;
    vector<int> v;
    vector<vector<int>> ret;
    back(k, n, 1, v, ret, sum);
    return ret;
}