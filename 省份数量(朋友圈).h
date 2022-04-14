#pragma once
#include<vector>
using namespace std;
//题目：省份数量/朋友圈
//题目描述：有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
//		省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
//		给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
//		返回矩阵中 省份 的数量。

//深度优先遍历，在visit中将已经遍历过的点置1
//O(N^2),O(N)，N为数组行列数
void findCircleNumCore(vector<vector<int>>& isConnected, vector<bool>& visited, int i)
{
    if (visited[i] == 1) return;//该点已经加入到省份，跳过该点
    visited[i] = 1;//加入省份
    for (int j = 0; j < isConnected.size(); j++)
        if (isConnected[i][j] == 1)  findCircleNumCore(isConnected, visited, j);//该点如果与其他点相邻，就递归其他点
}
int findCircleNum(vector<vector<int>>& isConnected) {
    if (isConnected.size() == 0)  return 0;
    int num = 0;
    vector<bool> visited(isConnected.size(), 0);//0表示该点尚未加入省份，1表示已经加入
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (visited[i] == 1) continue;//该点已经加入到省份，跳过该点
        findCircleNumCore(isConnected, visited, i);//将与该点在一个省份中的点全部遍历
        num++;//省份加一
    }
    return num;
}