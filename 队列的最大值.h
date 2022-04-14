#pragma once
#include<deque>
#include<queue>
#include<vector>
using namespace std;

class MaxQueue {
public:
    MaxQueue() {

    }

    int max_value()
    {
        if (queueMaxQueue.empty())
            return -1;
        return dequeMaxValue.front();
    }

    void push_back(int value)
    {
        queueMaxQueue.push(value);
        if (queueMaxQueue.empty())
        {
            dequeMaxValue.push_back(value);
            return;
        }

        if (value > dequeMaxValue.front())
        {
            dequeMaxValue.clear();
            dequeMaxValue.push_back(value);
            return;
        }

        while (1)
        {
            if (value <= dequeMaxValue.back())
            {
                dequeMaxValue.push_back(value);
                return;
            }
            else
            {
                dequeMaxValue.pop_back();
            }
        }
    }

    int pop_front()
    {
        if (queueMaxQueue.empty())
            return -1;

        int numPop = queueMaxQueue.front();
        
        if (numPop == dequeMaxValue.front())
            dequeMaxValue.pop_front();
        queueMaxQueue.pop();
        return numPop;
    }

public:
    queue<int> queueMaxQueue;
    deque<int> dequeMaxValue;
};