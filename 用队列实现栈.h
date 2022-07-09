#pragma once
#include<queue>
using namespace std;
//力扣225
//题目：用队列实现栈
//题干：请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。


//一个队列，在模拟栈弹出元素的时候只要将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部，此时在去弹出元素就是栈的顺序了。
class MyStack {
private:
    queue<int> q;
    int topNum;
public:
    MyStack() {
    }

    //O(1)
    void push(int x) {
        q.push(x);
        topNum = x;
    }


    int pop() {
        int temp;

        int len = q.size();
        //将队列头部的前len - 2个元素，重新添加到队列尾部
        for (int i = 0; i < len - 2; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }

        //记录第len - 1个元素为新的topNum，然后重新添加到队列尾部
        topNum = q.front();
        q.pop();
        q.push(topNum);

        //弹出第len个元素
        temp = q.front();
        q.pop();
        return temp;
    }

    //O(1)
    int top() {
        return topNum;
    }

    //O(1)
    bool empty() {
        return q.empty();
    }
};