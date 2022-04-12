#pragma once
#include<vector>
using namespace std;

//题目：
//题目描述：
//思路：寻找两个正序数组中的中位数，不就是寻找其中第k小的数的特殊情况吗，只是要根据两个数组长度之和的奇偶情况做分别处理


//函数：寻找两个正序数组中的第k小的数（二分法）
//该算法的思想：比较两个数组中的第k/2个数字
//              若A[k/2]<B[k/2],即使B中前k/2-1个元素均小于A[k/2]，由于数组递增，顶多有k-2个数字小于A[k/2]，
//              换言之，A[k/2]顶多是第k-1小，所以A中A[k/2]以及其之前的数字都不可能是第k小，故而被淘汰
//              更新一波k，并从被淘汰的数字之后开始新的迭代，直到k为1
//
double findKthSmallestInTwoSortedArray(vector<int>& nums1, vector<int>& nums2, int k)
{
    int start1 = 0, start2 = 0, cur1, cur2;
    while (k > 1)
    {
        //
        if (start1 == nums1.size())  return nums2[start2 + k - 1];
        if (start2 == nums2.size())  return nums1[start1 + k - 1];

        if (start1 + k / 2 - 1 > nums1.size() - 1) cur1 = nums1.size() - 1;
        else    cur1 = start1 + k / 2 - 1;
        if (start2 + k / 2 - 1 > nums2.size() - 1) cur2 = nums2.size() - 1;
        else    cur2 = start2 + k / 2 - 1;

        if (nums1[cur1] < nums2[cur2])
        {
            k -= (cur1 - start1 + 1);
            start1 = cur1 + 1;
        }
        else
        {
            k -= (cur2 - start2 + 1);
            start2 = cur2 + 1;
        }
    }
    if (start1 == nums1.size())  return nums2[start2 + k - 1];
    if (start2 == nums2.size())  return nums1[start1 + k - 1];
    return min(nums1[start1], nums2[start2]);
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size() + nums2.size();
    if (len & 1) return findKthSmallestInTwoSortedArray(nums1, nums2, len / 2 + 1);
    else    return (findKthSmallestInTwoSortedArray(nums1, nums2, len / 2) + findKthSmallestInTwoSortedArray(nums1, nums2, len / 2 + 1)) / 2;
}