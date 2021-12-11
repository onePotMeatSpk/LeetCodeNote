#pragma once
#include<vector>
#include<iostream>
using namespace std;
//��Ŀ����һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
//		Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�

//��ϣ��ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(N)
//int findRepeatNumber(vector<int>& nums) {
//	vector<int> hashtable(nums.size());
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (hashtable[nums[i]] != 0)
//			return nums[i];
//		else
//			hashtable[nums[i]]++;
//	}
//	return -1;
//}

//ԭ�ع�ϣ��ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(0)
//˼�룺������nums[i]����i��һ���ܲ�һ���ӣ���������ܲ������ظ�������
int findRepeatNumber(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++)
	{
		while (nums[i] != i)
		{
			if (nums[i] == nums[nums[i]])
				return nums[i];
			else
				swap(nums[i], nums[nums[i]]);
		}
	}
	return -1;
}
