#pragma once
#include<vector>
#include<stack>
using namespace std;
//����84
//��Ŀ����״ͼ�����ľ���
//��Ŀ���������� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��
//          ���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������


//����ջ
//˼·����ĳ��������Ϊ���εĸߣ���þ��ε�����������ڸ����ֵ����ҷ���ĵ�һ����С���ֵ����꣬����Ҫ����������������ջ����Ѱ�ҵ�һ����С���ֵ�����
int largestRectangleArea(vector<int>& heights) {
    int len = heights.size();
    if (len == 0)
        return 0;
    vector<int> minFront(len, -1);
    vector<int> minBack(len, len);
    stack<int> s;

    //Ѱ���ұߵ�һ����С���ֵ��±�
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

    //Ѱ����ߵ�һ����С���ֵ��±�
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
    //��i��������Ϊ���εĸߣ���þ����������
    for (int i = 0; i < len; i++)
    {
        int nowArea = (minBack[i] - minFront[i] - 1) * heights[i];
        maxArea = max(maxArea, nowArea);
    }

    return maxArea;
}