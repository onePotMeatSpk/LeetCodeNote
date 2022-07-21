#pragma once
#include<vector>
using namespace std;

//力扣39
//题目：组合总和_可有重复元素_返回vector
//题目描述：给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和
//			为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//			candidates 中的 同一个 数字可以   无限制重复   被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

//回溯法
void back(vector<int>& candidates, vector<vector<int>>& vAll, vector<int>& v, int target, int index = 0)
{
    if (target == 0)
    {
        vAll.push_back(v);
        return;
    }
    if (target < 0)
        return;

    for (int i = index; i < candidates.size(); i++)
    {
        v.push_back(candidates[i]);
        back(candidates, vAll, v, target - candidates[i], i);// 不用i+1了，表示可以重复读取当前的数
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> vAll;
    vector<int> v;
    back(candidates, vAll, v, target);
    return vAll;
}