#pragma once
#include<vector>
using namespace std;

//��Ŀ��
//��Ŀ������
//˼·��Ѱ���������������е���λ����������Ѱ�����е�kС���������������ֻ��Ҫ�����������鳤��֮�͵���ż������ֱ���


//������Ѱ���������������еĵ�kС���������ַ���
//���㷨��˼�룺�Ƚ����������еĵ�k/2������
//              ��A[k/2]<B[k/2],��ʹB��ǰk/2-1��Ԫ�ؾ�С��A[k/2]���������������������k-2������С��A[k/2]��
//              ����֮��A[k/2]�����ǵ�k-1С������A��A[k/2]�Լ���֮ǰ�����ֶ��������ǵ�kС���ʶ�����̭
//              ����һ��k�����ӱ���̭������֮��ʼ�µĵ�����ֱ��kΪ1
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