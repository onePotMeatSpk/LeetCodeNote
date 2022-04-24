#pragma once
#include<vector>
#include<queue>
using namespace std;
//题目：给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
//两个相邻元素间的距离为 1 。

//方法1，bfs
//从为0元素往外遍历，以为0元素为第0圈，一圈圈进行扩展
//O(N),O(N)
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dis(m, vector<int>(n, -1));
    //找到为0元素，将其距离置0
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == 0)
            {
                dis[i][j] = 0;
                q.push(make_pair(i, j));
            }

    int level = 0, levelNum;
    pair<int, int> cur, next;
    vector<int> turn{ 0, 1, 0, -1, 0 };
    while (!q.empty())
    {
        level++;//当前遍历圈数
        levelNum = q.size();
        while (levelNum--)
        {
            cur = q.front();//当前元素
            q.pop();
            //以当前元素为基，遍历四周元素
            for (int i = 0; i < 4; i++)
            {
                next.first = cur.first + turn[i];
                next.second = cur.second + turn[i + 1];
                if (next.first < 0 || next.first == m || next.second < 0 || next.second == n)   continue;//坐标越界
                if (dis[next.first][next.second] != -1 && dis[next.first][next.second] <= level)   continue;//下个元素已经被其他的0包含在更小的圈中了
                //下个元素还未被占据，当前0就是第一个探索到下个元素的0
                dis[next.first][next.second] = level;//当前0就是距离下个元素最近的0
                q.push(next);
            }
        }
    }

    return dis;
}

//方法2，dp
//从左往右、从上往下遍历一遍（确定某元素到其左上方向最近的0的距离），再从右往左、从下往上遍历一遍（确定某元素是否到其右下方向最近的0的距离更小）
//O(N),O(N)
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dis(m, vector<int>(n, 100000));
    //第一部分：从上往下、从左往右遍历，确认某元素与位于其左上方向的最近0的距离d1
    //初始化第一排、第一列
    if (mat[0][0] == 0)  dis[0][0] = 0;
    for (int j = 1; j < n; j++)
        if (mat[0][j] == 0)  dis[0][j] = 0;
        else    dis[0][j] = dis[0][j - 1] + 1;
    for (int i = 1; i < m; i++)
        if (mat[i][0] == 0)  dis[i][0] = 0;
        else    dis[i][0] = dis[i - 1][0] + 1;
    //遍历
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (mat[i][j] == 0)  dis[i][j] = 0;
            else    dis[i][j] = min(dis[i - 1][j], dis[i][j - 1]) + 1;

    //第一部分：从下往上、从右往左遍历，确认某元素与位于其右下方向的最近0的距离d2，将d2、d1相比，取最小值
    //初始化最后一排、最后一列
    for (int j = n - 2; j >= 0; j--)
        dis[m - 1][j] = min(dis[m - 1][j], dis[m - 1][j + 1] + 1);
    for (int i = m - 2; i >= 0; i--)
        dis[i][n - 1] = min(dis[i][n - 1], dis[i + 1][n - 1] + 1);
    //遍历
    for (int i = m - 2; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--)
            if (mat[i][j] != 0)  dis[i][j] = min(dis[i][j], min(dis[i + 1][j], dis[i][j + 1]) + 1);

    return dis;
}