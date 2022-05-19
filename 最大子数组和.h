#pragma once
#include<vector>
using namespace std;
//��Ŀ������������
//��Ŀ����������һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
//			������ �������е�һ���������֡�


//dp
//������������������У�����674��
int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    vector<int> dp(len, 0);

    dp[0] = nums[0];
    int maxSum = dp[0];
    for (int i = 1; i < len; i++)
    {
        dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        maxSum = maxSum > dp[i] ? maxSum : dp[i];
    }

    return maxSum;
}