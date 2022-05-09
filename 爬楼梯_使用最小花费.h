#pragma once
#include<vector>
using namespace std;

//����746
//��Ŀ����¥��_ʹ����С����
//��Ŀ����������һ���������� cost ������ cost[i] �Ǵ�¥�ݵ� i ��̨����������Ҫ֧���ķ��á�һ����֧���˷��ã�����ѡ��������һ����������̨�ס�
//			�����ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�
//			������㲢���شﵽ¥�ݶ�������ͻ��ѡ�

//dp
int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size() + 1, 0);
    for (int i = 2; i < cost.size() + 1; i++)
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);

    return dp[cost.size()];
}
