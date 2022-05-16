#pragma once
#include<vector>
#include<string>
using namespace std;

//力扣474
//题目：一和零
//题目描述：给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
//          请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
//          如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。


//01背包，两个维度的限制
// 背包：
//      一维重量限制：0的数量m
//      二维重量限制：1的数量n
//      价值：最大子集数量
// 物体：
//      物体是每个单一字符串
//      一维重量：字符串中0的数量
//      二维重量：字符串中1的数量
//      价值：1


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