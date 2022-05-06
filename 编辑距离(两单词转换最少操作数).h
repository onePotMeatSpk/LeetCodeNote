#pragma once
#include<vector>
#include<string>
using namespace std;
//力扣72
//题目：编辑距离（两单词转换最少操作数）
//题目描述：给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
//			你可以对一个单词进行如下三种操作：
//			插入一个字符
//			删除一个字符
//			替换一个字符
//
//			示例 ：
//			输入：word1 = "horse", word2 = "ros"
//			输出：3
//			解释：
//			horse->rorse(将 'h' 替换为 'r')
//			rorse->rose(删除 'r')
//			rose->ros(删除 'e')


//动态规划,二维数组
//dp[i][j]，表示将包含word1的前i个字符的子串，变换到包含word2的前j个字符的子串，最少需要几步操作。
// 有四种情况：
// 1、word1第i位和word2第j位 相同：这一位不需要操作，dp[i][j] = dp[i - 1][j - 1]
// 2、word1第i位和word2第j位 不同：这一位字符需要一次修改，dp[i][j] = dp[i - 1][j - 1] + 1，
// 3、i处删除：删除word1子串第i位，word1子串就只有前i-1位了，再在此基础上，变换到包含word2的前j个字符的子串的基础上，dp[i][j] = dp[i - 1][j] + 1
// 4j处增加：增加word2子串第j位，word1子串就只有前i-1位了，再在此基础上，变换到包含word2的前j个字符的子串的基础上，dp[i][j] = dp[i][j - 1] + 1
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n + 1; i++) dp[0][i] = i;
    for (int i = 0; i < m + 1; i++) dp[i][0] = i;

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
            dp[i][j] = min(dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1), min(dp[i][j - 1], dp[i - 1][j]) + 1);

    return dp[m][n];
}


