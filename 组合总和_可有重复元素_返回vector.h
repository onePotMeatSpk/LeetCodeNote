#pragma once
#include<vector>
using namespace std;

//力扣39
//题目：组合总和_可有重复元素_返回vector
//题目描述：给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和
//			为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//			candidates 中的 同一个 数字可以   无限制重复   被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

//回溯法
void back(vector<int>& candidates, const int& target, int& sum, vector<int>& v, vector<vector<int>>& ret, int index = 0)
{
    if (target == sum)
    {
        ret.push_back(v);
        return;
    }
    if (sum > target)    return;
    if (index == candidates.size() && target < sum)  return;

    for (; index < candidates.size(); index++)
        for (int i = 1; i <= (target - sum) / candidates[index]; i++)
        {
            sum += candidates[index] * i;
            for (int j = 0; j < i; j++)
                v.push_back(candidates[index]);

            back(candidates, target, sum, v, ret, index + 1);

            for (int j = 0; j < i; j++)
                v.pop_back();
            sum -= candidates[index] * i;
        }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    vector<int> v;
    int sum = 0;
    back(candidates, target, sum, v, ret, 0);
    return ret;
}