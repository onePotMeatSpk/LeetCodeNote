#pragma once
#include<stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        stackBack.push(x);
    }

    int pop() {
        if (stackFront.empty())
        {
            while (!stackBack.empty())
            {
                stackFront.push(stackBack.top());
                stackBack.pop();
            }
        }
        int temp = stackFront.top();
        stackFront.pop();
        return temp;
    }

    int peek() {
        if (stackFront.empty())
        {
            while (!stackBack.empty())
            {
                stackFront.push(stackBack.top());
                stackBack.pop();
            }
        }
        return stackFront.top();
    }

    bool empty() {
        if (stackFront.empty() && stackBack.empty())
            return true;
        return false;
    }

private:
    stack<int> stackBack;
    stack<int> stackFront;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */