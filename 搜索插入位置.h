#pragma once
#include<vector>
using namespace std;
//����35
//��Ŀ����������λ��
//��Ŀ����������һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
            //�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��

//���ַ�������ұ�
int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, mid = 0;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }

    //û�ҵ�target�Ļ�������mid�����target��ֵ�������϶���mid�Ա�
    //nums[mid] > target�Ļ����ǾͲ��� mid������ԭ��mid��ֵ����Ų
    //nums[mid] < target�Ļ����ǾͲ��� mid + 1��
    if (nums[mid] > target)
        return mid;
    else
        return mid + 1;
}