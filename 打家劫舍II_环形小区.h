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
//  1��������ͷ��β
//  2������ͷ��������β
//  3��������ͷ������β
//���У�1��2��3����������ֻ��Ҫ����2��3���ɡ�
int rob(vector<int>& nums) {
    int len = nums.size();
    if (len == 0)   return 0;
    if (len == 1)   return nums[0];
    if (len == 2)   return max(nums[0], nums[1]);;
    
    vector<int> dp(len, 0);

    //  2������ͷ��������β
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < len - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    int money = dp[len - 2];

    //  3��������ͷ������β
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for (int i = 3; i < len; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    money = money > dp[len - 1] ? money : dp[len - 1];

    return money;
}