#pragma once
#include<vector>
using namespace std;
//����416
//��Ŀ���ָ�Ⱥ��Ӽ�
//��Ŀ����������һ�� ֻ���������� �� �ǿ� ���� nums �������ж��Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�


//˼·��ֻ�������ܺ�sumΪż�����ſɷָ
//      ����sum/2�����£���ѡ�������Ԫ�ؿɴﵽ������Ԫ�غͣ�ÿ��Ԫ��ֻ��ʹ��1�Σ����Ԫ�غ��������sum/2����true��
//      �������ͱ����01�������⣬����������sum/2��������������Ʒ��ֵ���Ӽ�Ԫ�غͣ���Ʒ��������ֵ��������Ԫ��ֵ��
//      ���ڱ������������£���װ��Ʒ���Դﵽ������ֵ��ÿ����Ʒֻ��װ1�Ρ�

//dp,01������O(NM),O(NM)��û�н��пռ�ѹ��
bool canPartition(vector<int>& nums) {
    int n = nums.size(), w = 0, v;
    for (int i = 0; i < n; i++)  w += nums[i];
    if (w & 1)   return false;
    w >>= 1;
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        v = nums[i - 1];
        for (int j = 1; j <= w; j++)
            if (j >= v)  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v] + v);
            else    dp[i][j] = dp[i - 1][j];
    }
    if (dp[n][w] == w)   return true;
    return false;
}