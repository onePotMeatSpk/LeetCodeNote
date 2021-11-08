#pragma once
#include<vector>
#include<algorithm>
using namespace std;


//�����򣬺����
//ʱ�临�Ӷ�ΪO(5log5 )=O(1)
//�ռ临�Ӷ�ΪO(1)
bool isStraight(vector<int>& nums)
{
	//����ʹ�����Ϊ����
	sort(nums.begin(), nums.end());

	int countZero = 0;	//0�ĸ���
	int deviation = 0;	//�������������ֲ�ֵ

	//��������
	for (int i = 0; i < 5; i++)
	{
		//���������һ�˵��֮ǰ��ȫ������
		if (i == 4)
			return true;

		//����������0������ǰ����ͳ��������0�ĸ���
		if (nums[i] == 0)
		{
			countZero++;
			continue;
		}

		//0ͳ�����
		//����i����i+1�����ֲ�ֵ
		deviation = nums[i + 1] - nums[i];

		//������ȣ��Ƕ��ӣ�����false
		if (deviation == 0)
			return false;

		//������������������
		if (deviation == 1)
			continue;

		//��������������Ƚ������м�ȱ����0�����Ĺ�ϵ
		if (deviation - 1 > countZero)//ȱ��>0����
			return false;//��0����������ȱ�ڣ����鲻���ܱ�����������false
		else {//ȱ��<0����
			countZero -= (deviation - 1);//��0�ȱ�ڣ�������ʣ��0�ĸ���
			continue;//��������
		}
	}

	return false;
}