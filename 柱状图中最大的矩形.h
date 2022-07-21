#pragma once
#include<vector>
#include<stack>
using namespace std;
//力扣84
//题目：柱状图中最大的矩形
//题目描述：给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//          求在该柱状图中，能够勾勒出来的矩形的最大面积。


//单调栈
//思路：以某处数字作为矩形的高，则该矩形的面积，受制于该数字的左右方向的第一个更小数字的坐标，所以要构建两个单调不减栈，来寻找第一个更小数字的坐标
int largestRectangleArea(vector<int>& heights) {
    int len = heights.size();
    if (len == 0)
        return 0;
    vector<int> minFront(len, -1);
    vector<int> minBack(len, len);
    stack<int> s;

    //寻找右边第一个更小数字的下标
    for (int i = 0; i < len; )
    {
        if (!s.empty() && heights[i] < heights[s.top()])
        {
            minBack[s.top()] = i;
            s.pop();
        }
        else
            s.push(i++);
    }

    while (!s.empty())
        s.pop();

    //寻找左边第一个更小数字的下标
    for (int i = len - 1; i >= 0; )
    {
        if (!s.empty() && heights[i] < heights[s.top()])
        {
            minFront[s.top()] = i;
            s.pop();
        }
        else
            s.push(i--);
    }

    int maxArea = 0;
    //以i处数字作为矩形的高，求该矩形最大的面积
    for (int i = 0; i < len; i++)
    {
        int nowArea = (minBack[i] - minFront[i] - 1) * heights[i];
        maxArea = max(maxArea, nowArea);
    }

    return maxArea;
}