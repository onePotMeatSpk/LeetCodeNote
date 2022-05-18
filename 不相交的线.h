#pragma once
#include<vector>
using namespace std;
//力1035
//题目：不相交的线
//题目描述：在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
//			现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：
//			nums1[i] == nums2[j]
//			且绘制的直线不与任何其他连线（非水平线）相交。
//			请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
//			以这种方法绘制线条，并返回可以绘制的最大连线数。


//dp
//这不就是最长公共子序列吗？？
//相同数字可以连线，换言之，相同数字就是公共子序列的一部分
//线不可以相交，换言之，各对数字必须按照先后顺序连线
//那这不就是最长公共子序列吗？？
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = nums1[0] == nums2[0] ? 1 : 0;
    for (int j = 1; j < n; j++)
        if (nums2[j] == nums1[0])    dp[0][j] = 1;
        else if (dp[0][j - 1] == 1)  dp[0][j] = 1;

    for (int i = 1; i < m; i++)
        if (nums1[i] == nums2[0])    dp[i][0] = 1;
        else if (dp[i - 1][0] == 1)  dp[i][0] = 1;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = nums1[i] == nums2[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m - 1][n - 1];
}