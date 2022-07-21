#pragma once
#include<vector>
#include<stack>
using namespace std;
//����42
//��Ŀ������ˮ
//��Ŀ���������� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��

//����1����̬�滮�����н�ˮ
int trap(vector<int>& height)
{
    if (height.size() <= 2)
        return 0;

    int len = height.size();
    vector<int> next(len, 0);
    vector<int> prev(len, 0);

    int maxNum = 0;
    for (int i = 0; i < len; i++)
        if (maxNum > height[i])
            prev[i] = maxNum;
        else
            maxNum = height[i];

    maxNum = 0;
    for (int i = len - 1; i >= 0; i--)
        if (maxNum > height[i])
            next[i] = maxNum;
        else
            maxNum = height[i];

    int sum = 0;
    for (int i = 0; i < len; i++)
        if (prev[i] && next[i])
            sum += (min(prev[i], next[i]) - height[i]);

    return sum;
}

//����2������ջ�����н�ˮ
int trap(vector<int>& height)
{
    if (height.size() < 3)
        return 0;

    int len = height.size();
    int ret = 0;
    stack<int> s;

    for (int i = 0; i < len; )
    {
        if (!s.empty() && height[i] > height[s.top()])
        {
            int heightBottom = height[s.top()];
            s.pop();
            if (!s.empty())
                ret += (min(height[i], height[s.top()]) - heightBottom) * (i - s.top() - 1);

        }
        else
            s.push(i++);
    }

    return ret;
}