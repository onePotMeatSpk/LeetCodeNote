#pragma once
#include<vector>
#include<algorithm>
using namespace std;

//力扣15
//题目：三数之和 
//题目描述：给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
//          注意：答案中不可以包含重复的三元组。

//排序+双指针，O(N^2),O(1)
//如果暴力枚举，需要三层循环，为O(N^3)
//可以先将数组排序，然后将最内层的循环换为双指针法，以降低一个数量级的复杂度
//因为答案中不可以包含重复的三元组，所以要进行重复时的剪枝，共有三处需要进行剪枝
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> v;
    if (nums.size() < 3)    return v;
    //快排O(NlogN)
    sort(nums.begin(), nums.end());
    int l, r, target;
    //遍历iO(N)，快慢指针O(N-1)。共O(N^2)
    for (int i = 0; i <= nums.size() - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])    continue;//重复，剪枝
        target = -nums[i];//目标和
        l = i + 1;//左指针
        r = nums.size() - 1;//右指针
        while (l < r)
        {
            if (nums[l] + nums[r] > target)  r--;//大于目标和
            else if (nums[l] + nums[r] < target) l++;//小于目标和
            else
            {
                if (l != i + 1 && nums[l] == nums[l - 1])   l++;//重复，剪枝
                else if (r < nums.size() - 1 && nums[r] == nums[r + 1]) r--;//重复，剪枝
                else    v.push_back(vector<int>{nums[i], nums[l++], nums[r]});//和相等
            }
        }
    }
    return v;
}

//回溯法（复杂度不达标，超时）
void back(vector<int>& nums, vector<int>& used, vector<int>& v, vector<vector<int>>& vAll, int sum = 0, int index = 0)
{
    if (v.size() == 3)
    {
        if (sum == 0)
            vAll.push_back(v);
        return;
    }

    if (index == nums.size())
        return;

    if (sum > 0)
        return;

    for (int i = index; i < nums.size(); i++)
    {
        //去重
        if (i && nums[i] == nums[i - 1] && used[i - 1] == 0)
            continue;

        used[i] = 1;
        v.push_back(nums[i]);
        back(nums, used, v, vAll, sum + nums[i], i + 1);
        v.pop_back();
        used[i] = 0;
    }

}
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> used(nums.size(), 0);
    vector<int> v;
    vector<vector<int>> vAll;
    back(nums, used, v, vAll);
    return vAll;

}