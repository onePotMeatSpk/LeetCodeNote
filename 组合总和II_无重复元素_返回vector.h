#pragma once
#include<vector>
#include<algorithm>
using namespace std;

//力扣40
//题目：组合总和II_无重复元素_返回vector
//题目描述：给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//			candidates 中的每个数字在每个组合中只能使用 一次 。


//回溯
//used:元素使用情况
//sum：目前的和
//index：每层开始遍历的下标
void back(vector<int>& candidates, vector<bool>& used, const int& target, vector<int>& v, vector<vector<int>>& ret, int sum = 0, int index = 0) {
    if (sum == target)
    {
        ret.push_back(v);
        return;
    }
    if (sum > target)    return;
    if (index == candidates.size() && sum < target)  return;

    for (; index < candidates.size(); index++)
    {
        //如果当前元素和前元素相等，并且前元素没有被使用
        //则不可以使用当前元素，否则会导致重复结果
        //参照代码随想录解释，这样会导致同一层上的重复
        if (index > 0 && candidates[index] == candidates[index - 1] && used[index - 1] == 0)
            continue;

        v.push_back(candidates[index]);
        used[index] = 1;
        back(candidates, used, target, v, ret, sum + candidates[index], index + 1);
        used[index] = 0;
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<bool> used(candidates.size(), 0);
    vector<int> v;
    vector<vector<int>> ret;
    back(candidates, used, target, v, ret);
    return ret;
}

