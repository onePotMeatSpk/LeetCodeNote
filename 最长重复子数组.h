#pragma once
#include<vector>
using namespace std;
//����718
//��Ŀ����ظ�������
//��Ŀ�������������������� nums1 �� nums2 ������ ���������� ������ ���������������ĳ��� ��

//dp
//˼·������������������У�����674��
//dp[i][j]��num1��i��β��num2��j��β������������i��j��β�����������飬
//          dp[i][j]��¼�������������Ƿ񡰹���������������������dp[i][j]�ǹ������������󳤶ȣ�����������������dp[i][j]��0
//dp[i][j] = nums1[i] == nums2[j] ? dp[i - 1][j - 1] + 1 : 0��
//          i��jԪ����ȣ�����������ĳ�������Ϊ1�������ܲ��ܸ�����ȡ������i-1��j-1��β���������Ƿ񹫹������飬�䳤���Ƕ���
//          i��jԪ�ز��ȣ�������������϶����ǹ��������飬��Ȼ��������������ô�������������顱���ȵ�dp[i][j]��Ȼ��0
//
int findLength(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxLen = 0;
    for (int j = 0; j < n; j++)
        if (nums2[j] == nums1[0])
        {
            dp[0][j] = 1;
            maxLen = 1;
        }

    for (int i = 0; i < m; i++)
        if (nums1[i] == nums2[0])
        {
            dp[i][0] = 1;
            maxLen = 1;
        }

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = nums1[i] == nums2[j] ? dp[i - 1][j - 1] + 1 : 0;
            maxLen = maxLen > dp[i][j] ? maxLen : dp[i][j];
        }
    return maxLen;
}

