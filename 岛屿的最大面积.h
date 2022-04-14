#pragma once
#include<vector>
using namespace std;

//题目：岛屿的最大面积
//题目描述：给你一个大小为 m x n 的二进制矩阵 grid 。
//			岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
//			岛屿的面积是岛上值为 1 的单元格的数目。
//			计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

//深度优先遍历，将已经遍历过的位置置0
//O(M*N),O(1)，M、N为数组行列数
int maxAreaOfIslandCore(vector<vector<int>>& grid, int y, int x)
{
    if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size() || grid[y][x] == 0)  return 0;//越界，或此处非海，或已遍历
    grid[y][x] = 0;//置0，表示已遍历
    return 1 + maxAreaOfIslandCore(grid, y - 1, x) + maxAreaOfIslandCore(grid, y + 1, x)
        + maxAreaOfIslandCore(grid, y, x - 1) + maxAreaOfIslandCore(grid, y, x + 1);//递归四周
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) return 0;//鲁棒
    int max = 0, area;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
        {
            area = maxAreaOfIslandCore(grid, i, j);
            max = max < area ? area : max;//更新max
        }
    return max;
}
