#pragma once
#include<vector>
using namespace std;
//题目：最大正方形
//题目描述：在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

//dp，O(N),O(N)
//dp数组中，dp[i][j]表示，以[i][j]作为右下角的正方形的边长
//使用一个变量max，来记录已遍历过的区域的最大边长
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int max = 0;//max，表示已经遍历区域中，最大正方形的边长
    int leftSquare = 0;//leftSquare，表示以[i][j]的左边的元素[i][j-1]为右下角的正方形的边长
    int upSquare = 0;//upSquare，表示以[i][j]的上边的元素[i-1][j]为右下角的正方形的边长
    vector<vector<int>> matrixInt(m, vector<int>(n, 0));//matrixInt就是dp数组，记录以[i][j]为右下角的正方形的边长
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            matrixInt[i][j] = matrix[i][j] == '1' ? 1 : 0;
    //遍历最左边和最上边，因为如果在主循环体中讨论这两种特殊情况的话，会导致代码繁琐，所以率先遍历
    for (int i = 0; i < m; i++)  if (matrixInt[i][0] == 1)   max = 1;
    for (int j = 0; j < n; j++)  if (matrixInt[0][j] == 1)   max = 1;
    //主循环体，遍历其余部分
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
        {
            //[i][j]处为0，那不可能有正方形以此为右下角
            if (matrixInt[i][j] == 0)   continue;
            //[i][j]不为0
            leftSquare = matrixInt[i][j - 1];
            upSquare = matrixInt[i - 1][j];
            //leftSquare、upSquare相等
            if (leftSquare == upSquare)
            {
                //leftSquare为0，那么[i][j]就是其本身所组成的正方形的右下角
                if (leftSquare == 0);
                //leftSquare不为0，此处可以画图理解
                else if (matrixInt[i - upSquare][j - leftSquare] != 0)   matrixInt[i][j] = leftSquare + 1;
                else    matrixInt[i][j] = leftSquare;
            }
            //leftSquare、upSquare不等，画图理解
            else    matrixInt[i][j] = min(leftSquare, upSquare) + 1;
            //更新max
            max = matrixInt[i][j] > max ? matrixInt[i][j] : max;
        }

    return max * max;
}