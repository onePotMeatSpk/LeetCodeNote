#pragma once
#include<vector>
using namespace std;
//����674
//��Ŀ���������������
//��Ŀ����������һ��δ��������������飬�ҵ���� ���������������У������ظ����еĳ��ȡ�
//			���������������� �����������±� l �� r��l < r��ȷ�����������ÿ�� l <= i < r������ nums[i] < nums[i + 1] ��
//			��ô������[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] �����������������С�

//dp
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