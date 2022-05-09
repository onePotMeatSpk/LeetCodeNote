#pragma once
#include<vector>
using namespace std;
//����70
//��Ŀ����¥��
//��Ŀ������������������¥�ݡ���Ҫ n ������ܵ���¥����
//			ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

//dp
int climbStairs(int n) {
    if (n < 3)   return n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}