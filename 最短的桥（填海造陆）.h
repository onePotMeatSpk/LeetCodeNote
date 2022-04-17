#pragma once
#include<vector>
#include<queue>
using namespace std;
//题目：最短的桥
//题目描述:在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）
//          现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。
//          返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。）

//思路：dfs+bfs
//      dfs遍历岛1的所有陆地，并将其标记为已遍历（变值为2），还要将围绕岛1一圈的海域入队列
//      bfs从围绕岛1一圈的海域开始，一圈圈向外扩大，直到触碰到岛2，此时扩大的圈数就是桥的长度


//dfs函数
void dfsSearchOneIsland(vector<vector<int>>& grid, queue<pair<int, int>>& q, const int& m, const int& n, int y, int x)
{
    if (y < 0 || x < 0 || y >= m || x >= n || grid[y][x] == 2)   return;//越界，或者已遍历过
    if (grid[y][x] == 0)//此处为围绕岛1一圈的海域
    {
        q.push(make_pair(y, x));
        return;
    }
    grid[y][x] = 2;//将此处标记为已遍历（变值为2）
    //向周围dfs
    dfsSearchOneIsland(grid, q, m, n, y - 1, x);
    dfsSearchOneIsland(grid, q, m, n, y + 1, x);
    dfsSearchOneIsland(grid, q, m, n, y, x - 1);
    dfsSearchOneIsland(grid, q, m, n, y, x + 1);
}

//主函数
int shortestBridge(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int m = grid.size(), n = grid[0].size();
    //dfs阶段，遍历岛1
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)//只有当碰到岛1时，才会进行dfs
            {
                dfsSearchOneIsland(grid, q, m, n, i, j);//dfs
                goto bfsStage;//dfs完岛1后，即不再进行dfs，直接进入bfs阶段
            }

    //bfs阶段，从岛1的周围海域，一圈圈扩大搜索，直到触碰岛2
bfsStage:
    int direction[] = { 0, 1, 0, -1, 0 };
    int level = 0, levelNum;
    int y, x, nextY, nextX;
    while (!q.empty())//bfs常规流程
    {
        level++;
        levelNum = q.size();
        while (levelNum--)
        {
            y = q.front().first;
            x = q.front().second;
            grid[y][x] = 2;//将当前海域标记为已遍历
            q.pop();//出队
            for (int i = 0; i < 4; i++)//对当前海域四周进行bfs
            {
                nextY = y + direction[i];
                nextX = x + direction[i + 1];
                if (nextY < 0 || nextX < 0 || nextY >= m || nextX >= n || grid[nextY][nextX] == 2)   continue;//越界，或者已遍历过
                if (grid[nextY][nextX] == 1)   return level;//触碰到岛2！
                q.push(make_pair(nextY, nextX));
                grid[nextY][nextX] = 2;//将这个海域标记为已遍历（在此搭桥）
            }
        }
    }
    return 0;
}