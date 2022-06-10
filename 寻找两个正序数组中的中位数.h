#pragma once
#include<vector>
using namespace std;

//力扣4
//题目：寻找两个正序数组的中位数
//题目描述：给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//          算法的时间复杂度应该为 O(log(m + n)) 。
//思路:参考https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
//          寻找两个正序数组中的中位数，不就是寻找其中第k小的数的特殊情况吗，只是要根据两个数组长度之和的奇偶情况做分别处理




//函数：寻找两个正序数组中的第k小的数（二分法）
//该算法的思想：比较两个数组中的第k/2个数字
//              若A[k/2]<B[k/2],即使B中前k/2-1个元素均小于A[k/2]，由于数组递增，顶多有k-2个数字小于A[k/2]，
//              换言之，A[k/2]顶多是第k-1小，所以A中A[k/2]以及其之前的数字都不可能是第k小，故而被淘汰
//              更新一波k，并从被淘汰的数字之后开始新的迭代，直到k为1
//
double KthSmallin2SortedArray(vector<int>& nums1, vector<int>& nums2, int k)
{
    int start1 = 0, start2 = 0, cur1, cur2;
    while (k > 1 && start1 < nums1.size() && start2 < nums2.size())
    {
        //如果nums1中剩余数字，不够k/2个了，就使用最后一个数字，与nums2作比较
        //如果够k/2个，就使用第start1 + k / 2 - 1个数字（也就是剩余数字中的，第k/2个数字），与nums2作比较
        if (start1 + k / 2 - 1 > nums1.size() - 1) cur1 = nums1.size() - 1;
        else    cur1 = start1 + k / 2 - 1;
        //nums2同nums1处理方式
        if (start2 + k / 2 - 1 > nums2.size() - 1) cur2 = nums2.size() - 1;
        else    cur2 = start2 + k / 2 - 1;

        //nums1[cur1] <= nums2[cur2]，那么nums1[cur1]之前（含）的数字都不可能是第k小的数字，则抛弃nums1[cur1]之前（含）的所有数字
        if (nums1[cur1] <= nums2[cur2])
        {
            k -= (cur1 - start1 + 1);
            start1 = cur1 + 1;
        }
        //同上道理
        else
        {
            k -= (cur2 - start2 + 1);
            start2 = cur2 + 1;
        }
    }

    //如果循环是因为start1 < nums1.size() && start2 < nums2.size()退出，说明其中一个数组中已经没有剩余数字了
    if (start1 == nums1.size())  return nums2[start2 + k - 1];//如果nums1中无剩余数字了，就直接取nums2中第k个
    if (start2 == nums2.size())  return nums1[start1 + k - 1];//同上道理

    //如果循环是因为k=1退出，现在就是取两数组的第1小的值
    return min(nums1[start1], nums2[start2]);//取两数组首元素的最小值
}

//主函数
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size() + nums2.size();

    //总长为奇数
    if (len & 1) return KthSmallin2SortedArray(nums1, nums2, len / 2 + 1);
    //总长为偶数
    else    return (KthSmallin2SortedArray(nums1, nums2, len / 2) + KthSmallin2SortedArray(nums1, nums2, len / 2 + 1)) / 2;
}