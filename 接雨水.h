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
    if (height.size() < 3)
        return 0;

    int len = height.size();
    vector<int> maxFront(len, 0);
    vector<int> maxBack(len, 0);

    int temp = height[0];
    for (int i = 0; i < len; i++)
    {
        maxFront[i] = height[i] > temp ? height[i] : temp;
        temp = height[i] > temp ? height[i] : temp;
    }

    temp = height[len - 1];
    for (int i = len - 1; i >= 0; i--)
    {
        maxBack[i] = height[i] > temp ? height[i] : temp;
        temp = height[i] > temp ? height[i] : temp;
    }

    temp = 0;

    for (int i = 1; i < len - 1; i++)
        temp += min(maxFront[i], maxBack[i]) - height[i];

    return temp;
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