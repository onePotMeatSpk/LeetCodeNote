#pragma once
#include<vector>
#include<string>
using namespace std;

//����474
//��Ŀ��һ����
//��Ŀ����������һ���������ַ������� strs ���������� m �� n ��
//          �����ҳ������� strs ������Ӽ��ĳ��ȣ����Ӽ��� ��� �� m �� 0 �� n �� 1 ��
//          ��� x ������Ԫ��Ҳ�� y ��Ԫ�أ����� x �Ǽ��� y �� �Ӽ� ��


//01����������ά�ȵ�����
// ������
//      һά�������ƣ�0������m
//      ��ά�������ƣ�1������n
//      ��ֵ������Ӽ�����
// ���壺
//      ������ÿ����һ�ַ���
//      һά�������ַ�����0������
//      ��ά�������ַ�����1������
//      ��ֵ��1


int findMaxForm(vector<string>& strs, int m, int n) {
    vector<pair<int, int>> count01;
    for (int i = 0; i < strs.size(); i++)
    {
        int count0 = 0, count1 = 0;
        for (int j = 0; j < strs[i].size(); j++)
            if (strs[i][j] == '0')   count0++;
            else    count1++;
        count01.push_back(make_pair(count0, count1));
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < strs.size(); i++)
        for (int j = m; j >= count01[i].first; j--)
            for (int k = n; k >= count01[i].second; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - count01[i].first][k - count01[i].second] + 1);
            }

    return dp[m][n];
}