#pragma once
#include<vector>
using namespace std;
//题目：太平洋大西洋水流问题
//题目描述：给定一个二维的非负整数矩阵，每个位置的值表示海拔高度。假设左边和上边是太平洋，右边和下边是大西洋。
//			求从哪些位置向下流水，可以既能流到太平洋，又能流到大西洋。水只能从海拔高的位置流到海拔低或相同的位置。

//算法思想：从内陆某点出发，通过找四周点中小于等于当前点的点进行遍历的话，在判断某点是否可以同时到达两洋上会很麻烦
//不如从海边的点进行遍历，海边的点是肯定可以到达其紧邻的大洋的，再找大于等于当前点的点，就说明那个点肯定可以经由当前点到达该大洋
//将两个大洋分开来讨论，得到可以到达某个大洋的点的矩阵，如果在某点在两个矩阵上都是1，说明该点可以同时到达两个大洋



//递归函数
void pacificAtlanticCore(vector<vector<int>>& heights, vector<vector<bool>>& valley, const int& m, const int& n, int y, int x)
{
    if (valley[y][x])    return;//如果该点已经确定可以流到大海，就不再管该点
    valley[y][x] = 1;//已经遍历到了该点，就说明该点铁定可以流到大海
    //如果四周点中的某个的海拔高于当前点，那它肯定可以流到当前点，又因当前点肯定可以流到大海，那么那个点也肯定可以流到大海，所以遍历那个点以找到更多的点
    //注意边界控制，防止数组索引越界
    if (y - 1 >= 0 && heights[y - 1][x] >= heights[y][x])  pacificAtlanticCore(heights, valley, m, n, y - 1, x);
    if (y + 1 < m && heights[y + 1][x] >= heights[y][x])  pacificAtlanticCore(heights, valley, m, n, y + 1, x);
    if (x - 1 >= 0 && heights[y][x - 1] >= heights[y][x])  pacificAtlanticCore(heights, valley, m, n, y, x - 1);
    if (x + 1 < n && heights[y][x + 1] >= heights[y][x])  pacificAtlanticCore(heights, valley, m, n, y, x + 1);
}

//主函数
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> valleyPacific(m, vector<bool>(n, 0));//可到达太平洋的点
    vector<vector<bool>> valleyAtlantic(m, vector<bool>(n, 0));//可到达大西洋的点
    vector<vector<int>> route;//可同时到达两洋的点

    //处理太平洋，从紧邻太平洋的海岸开始遍历
    for (int i = 0; i < m; i++)  pacificAtlanticCore(heights, valleyPacific, m, n, i, 0);
    for (int i = 0; i < n; i++)  pacificAtlanticCore(heights, valleyPacific, m, n, 0, i);
    //处理大西洋，从紧邻大西洋的海岸开始遍历
    for (int i = 0; i < m; i++)  pacificAtlanticCore(heights, valleyAtlantic, m, n, i, n - 1);
    for (int i = 0; i < n; i++)  pacificAtlanticCore(heights, valleyAtlantic, m, n, m - 1, i);

    //提取出同时可以到达两洋的点
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (valleyPacific[i][j] && valleyAtlantic[i][j]) route.push_back(vector<int>{i, j});

    return route;
}