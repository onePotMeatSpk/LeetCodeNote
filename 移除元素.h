#pragma once
#include<vector>
using namespace std;
//力扣27
//题目：移除元素
//题目描述：给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
		//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
		//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。


//二分法
//快指针遍历处理前的数组元素，遇到val就跳过，遇到非val就传给慢指针
//慢指针承接快指针传来的元素，构成处理后的数组，慢指针最后的值，就是处理后数组的长度
int removeElement(vector<int>& nums, int val) {
    int l = 0, r = 0;

    while (l < nums.size() && r < nums.size())
    {
        if (nums[r] != val)
            nums[l++] = nums[r++];
        else
            r++;
    }

    return l;
}