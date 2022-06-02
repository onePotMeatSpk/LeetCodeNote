#pragma once
#include<vector>
#include<unordered_set>
using namespace std;
//力扣491
//题目：递增子序列
//题目描述：给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
//			数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。


//思路：准确地说，其实是不递减子序列，因为允许两元素相等。
//      和子集II的思路大致一样，只是去重方法不一样。
//      子集II对顺序无要求，所以其去重，是通过排序使得重复元素紧邻，使用一个贯穿所有层的used数组来记录某坐标元素是否被使用，然后在每层中查看重复元素的前方元素是否未被使用。
//      该题对顺序有要求，所以不可对数组排序，既然去重的目的，是防止一层内出现重复，所以可以在每层中设置一个setUsed，来记录某数字是否被使用过，如果for遍历到碰到某数字，发现其已经在setUsed中，说明其在该层已经被使用过，不应该再被使用了。

//回溯
//
void back(vector<int>& nums, vector<int>& v, vector<vector<int>>& ret, int index = 0) {

    if (v.size() >= 2)   ret.push_back(v);
    if (index == nums.size())    return;

    unordered_set<int> setUsed;//在每层中设置setUsed，专门记录该层各数字的使用情况
    for (; index < nums.size(); index++)
    {
        if (v.size() && nums[index] < v.back())  continue;//当前数字不满足递增要求，则不使用
        if (setUsed.find(nums[index]) != setUsed.end())  continue;//当前数字是重复数字，且已经在该层中的前面枝丫使用过，所以不应该再使用了，否则会重复

        setUsed.insert(nums[index]);//将当前元素放入setUsed，以表示已经使用过
        v.push_back(nums[index]);
        back(nums, v, ret, index + 1);
        v.pop_back();
    }

}

//主函数
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> v;
    vector<vector<int>> ret;

    back(nums, v, ret);
    return ret;
}