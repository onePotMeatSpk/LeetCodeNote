#pragma once
#include<vector>
using namespace std;
//题目：有序数组中的单一元素
//题目描述：给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。请你找出并返回只出现一次的那个数。

//二分法，时间复杂度O(logN)，空间复杂度O(1),
//该题必须画图理解！该算法需要保证经过每次迭代后，新区间长度都为奇数，这样才能既包含target，又包含各对成对元素
int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid, wingLen;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        wingLen = mid - l;//两翼长度
        if (nums[mid] == nums[mid - 1])//若mid元素与前方元素相等
        {
            if (wingLen & 1) l = mid + 1;//若两翼长度为奇，则target在mid之后，为保证新区间长度仍为奇数，故而不需要将mid元素算进新区间，l = mid + 1
            else    r = mid;//若两翼长度为偶，则target在mid之前，为保证新区间长度仍为奇数，故而需要将mid元素算进新区间，r = mid 
        }
        else if (nums[mid] == nums[mid + 1])//若mid元素与后方元素相等
        {
            if (wingLen & 1) r = mid - 1;//若两翼长度为奇，则target在mid之前，为保证新区间长度仍为奇数，故而不需要将mid元素算进新区间，r = mid - 1
            else    l = mid;//若两翼长度为偶，则target在mid之后，为保证新区间长度仍为奇数，故而需要将mid元素算进新区间，l = mid 
        }
        else    return nums[mid];//与前后都不相等，必是孤单元素
    }
    return nums[l];//区间只剩一个元素中时，就是孤单元素
}

//这个算法为网上的算法（java实现），思想与本人方法一样，但是更为简洁
// 省去了根据mid与前后元素的关系、两翼奇偶情况做分别处理的过程，
// 而是在两翼为奇数时，直接将mid前移一位，这样就将两翼长度变为了偶数
// 所有的mid都仅和nums[mid+1]作比较（经过mid前移之后，奇数长度的两翼变为偶数长度，这样mid和mid+1比较其实就是本来的mid-1和mid比较）
// 太TM的妙了！！！！！！
//class Solution {
//    public int singleNonDuplicate(int[] nums) {
//        int l = 0, r = nums.length - 1, m;
//        while (l < r) {
//            m = l + (r - l) / 2;
//            if (m % 2 == 1) {
//                m--;
//            }
//            if (nums[m] == nums[m + 1]) {
//                l = m + 2;
//            }
//            else {
//                r = m;
//            }
//        }
//        return nums[l];
//    }
//}