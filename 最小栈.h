#pragma once
#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        if (stackNums.empty())
        {
            stackNums.push(val);
            stackMins.push(val);
            return;
        }

        if (val <= stackMins.top())
        {
            stackNums.push(val);
            stackMins.push(val);
        }
        else
        {
            stackNums.push(val);
        }
    }

    void pop() {
        if (stackNums.empty())
            return;

        if (stackNums.top() != stackMins.top())
            stackNums.pop();
        else
        {
            stackNums.pop();
            stackMins.pop();
        }
    }

    int top() {
        return stackNums.top();
    }

    int getMin() {
        return stackMins.top();
    }

private:
    stack<int> stackMins;
    stack<int> stackNums;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */