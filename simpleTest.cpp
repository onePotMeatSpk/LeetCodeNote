#pragma once
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<typeinfo>
#include<stack>
#include<iostream>
#include<queue>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"组合总和_可有重复元素_返回vector.h"



bool back(vector<int>& nums, vector<bool>& used, int k, int& sum, int need)
{
    if (k == 0)
        return true;

    for (int i = 0; i < nums.size() && nums[i] <= need; i++)
    {
        if (used[i] == 1)
            continue;

        used[i] = 1;
        if (nums[i] == need)
        {
            if (back(nums, used, k - 1, sum, sum))
                return true;
        }
        else
            if (back(nums, used, k, sum, need - nums[i]))
                return true;
        used[i] = 0;
    }

    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (int i : nums)
        sum += i;

    //除尽
    if (sum % k != 0)
        return false;

    sum = sum / k;
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), 0);
    //回溯
    return back(nums, used, k, sum, sum);
}

int main(int argc, char** argv) {
    vector<int> nums{ 114,96,18,190};

    canPartitionKSubsets(nums, 4);
}