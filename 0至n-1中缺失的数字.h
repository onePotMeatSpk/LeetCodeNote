#pragma once
#include<iostream>
#include<vector>
using namespace std;

//�ú�������˼������[left,right]�������ڽ��ж�������
int missingNumberCore(vector<int>& nums, int left, int right)
{
	if (right < left)	return -1;//˵��numsΪ��
	if (left == right)//left==right������Ҫ�ﵽ��Ч��
	{
		if (left == nums.size() - 1)//left������ĩβʱ�������ֿ���
		{
			if (nums[left] > left)	return left;//��һ�֣�ȱʧ��Ԫ����n-2
			if (nums[left] == left)	return left + 1;//�ڶ��֣�ȱʧ��Ԫ����n-1
		}
		return left;//left��Ϊ����ĩβʱ��left�������ȱʧ��Ԫ��
	}

	int mid = left + (right - left) / 2;
	if (nums[mid] > mid)	return missingNumberCore(nums, left, mid);//���mid��Ԫ�ش���mid����˵��mid��ߣ���mid����Ԫ��ȱʧ��������ֲ���
	if (nums[mid] == mid)	return missingNumberCore(nums, mid + 1, right);//���mid��Ԫ�ص���mid����˵��mid�ұߣ�����mid����Ԫ��ȱʧ�����Ҷ��ֲ���
	return -1;//³�����ƣ���֤��������¶��з���ֵ
}

int missingNumber(vector<int>& nums)
{
	return missingNumberCore(nums, 0, nums.size() - 1);
}