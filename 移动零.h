#pragma once
#include<vector>
using namespace std;
//力扣283
//题目：移动零
//题目描述：给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
            //请注意 ，必须在不复制数组的情况下原地对数组进行操作。


//二分法
//前半部分，与力扣27移除元素思路相同（只不过移除元素确定为0）
//后半部分，在慢指针之后的所有位置，填充0
void moveZeroes(vector<int>& nums) {
    int l = 0, r = 0;

    while (r < nums.size())
    {
        if (nums[r] == 0)
            r++;
        else
            nums[l++] = nums[r++];
    }

    while (l < nums.size())
        nums[l++] = 0;
}
