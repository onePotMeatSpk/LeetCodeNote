#pragma once
#include<vector>
using namespace std;
//力扣77
//题目：组合
//题目描述：给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。你可以按 任何顺序 返回答案。


//k：需要的剩余数字个数（剪枝）
//index：开始遍历的坐标
void back(const int& n, int k, int index, vector<int>& v, vector<vector<int>>& ret)
{
    if (k == 0) {
        ret.push_back(v);
        return;
    }
    if (k > n - index + 1)   return;

    for (; index <= n; index++)
    {
        v.push_back(index);
        back(n, k - 1, index + 1, v, ret);
        v.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<int> v;
    vector<vector<int>> ret;
    back(n, k, 1, v, ret);
    return ret;
}