#pragma once
#include<vector>
using namespace std;

//����213
//��Ŀ����ҽ���II_����С��
//��Ŀ����������ط����еķ��ݶ� Χ��һȦ ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�
//          ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ����� ��
//          ����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ �ڲ���������װ�õ������ �������ܹ�͵�Ե�����߽�


//dp
//����ɻ�֮�������������
//  1��������͵ͷ��β
//  2��������͵β
//  3��������͵ͷ
//���У�1��2��3����������ֻ��Ҫ����2��3���ɡ�
int help(vector<int>& nums, int start, int end)
{
    vector<int> dp(end - start + 2, 0);
    dp[0] = 0;
    dp[1] = nums[start];

    for (int i = 2; i < dp.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i - 1]);

    return dp[dp.size() - 1];
}
int rob(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];

    //������͵β��     
    int ret0 = help(nums, 0, nums.size() - 2);
    //������͵ͷ��
    int ret1 = help(nums, 1, nums.size() - 1);

    return max(ret0, ret1);
}