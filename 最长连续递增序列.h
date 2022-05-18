#pragma once
#include<vector>
using namespace std;
//����674
//��Ŀ���������������
//��Ŀ����������һ��δ��������������飬�ҵ���� ���������������У������ظ����еĳ��ȡ�
//			���������������� �����������±� l �� r��l < r��ȷ�����������ÿ�� l <= i < r������ nums[i] < nums[i + 1] ��
//			��ô������[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] �����������������С�

//dp
//dp[i]������i��β�������飬�����һ���������飬��ô����󳤶��Ƕ���
//dp[i] = nums[i] > nums[i - 1] ? dp[i - 1] + 1 : 1��
//          nums[i] > nums[i - 1] ��i-1��i��������������������飬���������ܲ��ܸ�����ȡ������i-1��β�������������������󳤶�dp[i - 1]
//          nums[i] <= nums[i - 1]��i-1��i��������������������飬��ô�����i��ʼ�����½���һ���������������飬i����ͷҲ��β��dp[i]=1
int findLengthOfLCIS(vector<int>& nums) {
    int len = nums.size();
    vector<int> dp(len, 1);

    int maxLen = 1;
    for (int i = 1; i < len; i++)
    {
        dp[i] = nums[i] > nums[i - 1] ? dp[i - 1] + 1 : 1;
        maxLen = maxLen > dp[i] ? maxLen : dp[i];
    }

    return maxLen;
}