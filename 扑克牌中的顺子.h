#pragma once
#include<vector>
#include<algorithm>
using namespace std;


//先排序，后遍历
//时间复杂度为O(5log5 )=O(1)
//空间复杂度为O(1)
bool isStraight(vector<int>& nums)
{
	//排序，使数组变为递增
	sort(nums.begin(), nums.end());

	int countZero = 0;	//0的个数
	int deviation = 0;	//数组中相邻数字差值

	//遍历数组
	for (int i = 0; i < 5; i++)
	{
		//遍历到最后一项，说明之前项全部连续
		if (i == 4)
			return true;

		//递增数组中0挤在最前，先统计数组中0的个数
		if (nums[i] == 0)
		{
			countZero++;
			continue;
		}

		//0统计完后
		//计算i处与i+1处数字差值
		deviation = nums[i + 1] - nums[i];

		//两处相等，是对子，返回false
		if (deviation == 0)
			return false;

		//两处连续，遍历下轮
		if (deviation == 1)
			continue;

		//两处不连续，则比较两处中间缺口与0数量的关系
		if (deviation - 1 > countZero)//缺口>0数量
			return false;//则0不足以填满缺口，数组不可能变连续，返回false
		else {//缺口<0数量
			countZero -= (deviation - 1);//用0填补缺口，并更新剩余0的个数
			continue;//继续遍历
		}
	}

	return false;
}