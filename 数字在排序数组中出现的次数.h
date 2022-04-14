#pragma once
#include"��������.h"
using namespace std;

//ȷ��target�״���ĩ�γ��ֵ�λ�õĺ��������ַ���
//����ֵΪ1˵����������target��Ϊ0˵��û��
int searchCore(vector<int>& nums, int target, int left, int right, int& indexOfFirstTarget, int& indexOfLastTarget)
{
	/*
	����㷨�ĺ���˼�����ڣ����ö��ַ�������
	���mid��Ԫ�ز�����target������ݴ�С��ϵ�����߲���
	���mid��Ԫ�ص���target�������һ�����ķ���mid���Ԫ��С��mid��Ԫ����˵��mid��target�״γ���λ�ã�mid�ұ�Ԫ�ش���mid��Ԫ����˵��mid��targetĩ�γ���λ��
	*/

	if (left > right)//�����Ѿ����ն��ַ��������
	{
		if ((indexOfFirstTarget == -1) && (indexOfLastTarget == -1))	return 0;//�������λ�ò�����Ϊ��ʼֵ��˵��������û�ҵ�target
		return 1;
	}
	int mid = left + (right - left) / 2;
	if (nums[mid] < target)	return searchCore(nums, target, mid + 1, right, indexOfFirstTarget, indexOfLastTarget);//mid��Ԫ��С��target���������ֲ���
	if (nums[mid] > target)	return searchCore(nums, target, left, mid - 1, indexOfFirstTarget, indexOfLastTarget);//mid��Ԫ�ش���target������ǰ���ֲ���
	//������mid��Ԫ�ص���target�����
	if (mid == 0)//��midλ��������߽�
	{
		if (nums[mid + 1] > target)
		{
			indexOfFirstTarget = mid;
			indexOfLastTarget = mid;
			return 1;
		}
		if (nums[mid + 1] == target)
		{
			indexOfFirstTarget = mid;
			return searchCore(nums, target, mid + 1, right, indexOfFirstTarget, indexOfLastTarget);
		}
	}
	if (mid == nums.size() - 1)//��midλ�������ұ߽�
	{
		if (nums[mid - 1] < target)
		{
			indexOfFirstTarget = mid;
			indexOfLastTarget = mid;
			return 1;
		}
		if (nums[mid - 1] == target)
		{
			indexOfLastTarget = mid;
			return searchCore(nums, target, left, mid - 1, indexOfFirstTarget, indexOfLastTarget);
		}
	}
	//������midλ�������м�����
	if ((nums[mid - 1] < target) && (nums[mid + 1] > target))
	{
		indexOfFirstTarget = mid;
		indexOfLastTarget = mid;
		return 1;
	}
	if ((nums[mid - 1] < target) && (nums[mid + 1] == target))
	{
		indexOfFirstTarget = mid;
		return searchCore(nums, target, mid + 1, right, indexOfFirstTarget, indexOfLastTarget);
	}
	if ((nums[mid - 1] == target) && (nums[mid + 1] > target))
	{
		indexOfLastTarget = mid;
		return searchCore(nums, target, left, mid - 1, indexOfFirstTarget, indexOfLastTarget);
	}
	if ((nums[mid - 1] == target) && (nums[mid + 1] == target))
	{
		searchCore(nums, target, mid + 1, right, indexOfFirstTarget, indexOfLastTarget);
		return searchCore(nums, target, left, mid - 1, indexOfFirstTarget, indexOfLastTarget);
	}
	return 0;
}
int search(vector<int>& nums, int target) {
	if (nums.empty())	return 0;
	if ((nums.size() == 1) && (nums[0] == target))	return 1;
	if ((nums.size() == 1) && (nums[0] != target))	return 0;
	int indexOfFirstTarget = -1, indexOfLastTarget = -1;
	if(searchCore(nums, target, 0, nums.size() - 1, indexOfFirstTarget, indexOfLastTarget))	return indexOfLastTarget - indexOfFirstTarget + 1;
	return 0;
}