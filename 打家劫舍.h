#pragma once
#include<vector>
using namespace std;

//����198
//��Ŀ����ҽ���
//��Ŀ���������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
//			����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�

//dp
int rob(vector<int>& nums) {
    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];

    for (int i = 2; i <= nums.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);

    return dp[nums.size()];
}
