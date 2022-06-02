#pragma once
#include<deque>
#include<queue>
using namespace std;
//剑指 Offer 59 - II. 队列的最大值
//题目：队列的最大值
//题目描述：请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
//          若队列为空，pop_front 和 max_value 需要返回 - 1


class MaxQueue {
public:
    queue<int> q;
    deque<int> d;
    MaxQueue() {
    }

    int max_value() {
        //鲁棒
        if (q.empty())   return -1;
        //返回栈顶
        return d.front();
    }

    void push_back(int value) {
        //处理最大值
        //队列不空
        if (!q.empty())
        {
            //value大于最大值
            if (value > d.front())
            {
                d.clear();//将deque清空
                d.push_back(value);//随后将value放入
            }
            else
            {
                while (d.back() < value) d.pop_back();//将deque后部，小于value的值清空
                d.push_back(value);//随后将value放入
            }
        }
        //队列为空，value就是最大值，直接放入即可
        else    d.push_back(value);

        //处理队列
        q.push(value);

        return;
    }

    int pop_front() {
        //鲁棒
        if (q.empty())   return -1;
        //弹出队首
        int temp = q.front();
        q.pop();
        //如果队首与最大值相同，则弹出deque中最大值
        if (temp == d.front()) d.pop_front();
        //返回队首
        return temp;
    }
};