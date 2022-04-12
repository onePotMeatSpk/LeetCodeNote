#pragma once
#include<vector>
using namespace std;

//��Ŀ�������еĵ�K�����Ԫ��
//��Ŀ�����������еĵ�K�����Ԫ��
//˼·����ѡ

//�����ѡ����
int randomizedPartition(vector<int>& nums, int l, int r)
{
    swap(nums[l], nums[rand() % (r - l + 1) + l]);//partition֮ǰ�������飬�Է�O(N^2)
    return partition(nums, l, r);
}

//��ѡ����
int partition(vector<int>& nums, int l, int r)
{
    int key = l;
    while (l < r)
    {
        while ((l < r) && (nums[r] >= nums[key]))  r--;
        while ((l < r) && (nums[l] <= nums[key]))  l++;
        swap(nums[l], nums[r]);
    }
    swap(nums[key], nums[l]);
    return l;
}

//������
int findKthLargest(vector<int>& nums, int k) {
    if (k > nums.size()) return -1;
    int l = 0, r = nums.size() - 1, mid;
    while (true)
    {
        mid = randomizedPartition(nums, l, r);
        if (mid == nums.size() - k)  return nums[mid];
        else if (mid < nums.size() - k)  l = mid + 1;
        else    r = mid - 1;
    }
    return 0;
}