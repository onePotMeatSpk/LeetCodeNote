#pragma once
#include<vector>
using namespace std;
//题目：组合
//题目描述：给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。你可以按 任何顺序 返回答案。

//dfs函数
void combineCore(const int& n, const int& k, vector<bool>& used, vector<vector<int>>& vAll, vector<int>& v, int index)
{
    if (v.size() == k)
    {
        vAll.push_back(v);
        return;
    }
    if (index == n)  return;

    for (int i = index + 1; i < n + 1; i++)
        if (used[i] == 0)
        {
            used[i] = 1;
            v.push_back(i);
            combineCore(n, k, used, vAll, v, i);
            v.pop_back();
            used[i] = 0;
        }
}

//主函数
vector<vector<int>> combine(int n, int k) {
    vector<bool> used(n + 1, 0);
    vector<vector<int>> vAll;
    vector<int> v;
    combineCore(n, k, used, vAll, v, 0);
    return vAll;
}