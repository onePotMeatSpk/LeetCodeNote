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
void back(const vector<int>& candidates, vector<bool>& used, vector<int>& v, vector<vector<int>>& vAll, int target, int index = 0)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        vAll.push_back(v);
        return;
    }


    for (int i = index; i < candidates.size() && target >= candidates[i]; i++)//target >= candidates[i]用来剪枝
    {
        //去重
        //如果当前元素和前元素相等，并且前元素没有被使用
        //则不可以使用当前元素，否则会导致重复结果
        //参照代码随想录解释，这样会导致同一层上的重复
        if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0)
            continue;

        v.push_back(candidates[i]);
        used[i] = 1;
        back(candidates, used, v, vAll, target - candidates[i], i + 1);
        used[i] = 0;
        v.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //想要去重，必须先排序，使相同数字相邻
    sort(candidates.begin(), candidates.end());
    vector<bool> used(candidates.size(), 0);
    vector<int> v;
    vector<vector<int>> vAll;
    back(candidates, used, v, vAll, target);
    return vAll;
}

