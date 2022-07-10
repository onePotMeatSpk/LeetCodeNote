#pragma once
#include<deque>
#include<vector>
using namespace std;
//力扣239
//滑动窗口的最大值
//题干：给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
        //你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
        //返回 滑动窗口中的最大值 。


class MyQueue
{
private:
    deque<int> dq;
public:
    void push(int x)
    {
        while (!dq.empty() && dq.back() < x)
            dq.pop_back();
        dq.push_back(x);
    }

    void pop(int x)
    {
        if (x == dq.front())
            dq.pop_front();
    }

    int front()
    {
        return dq.front();
    }

};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ret;
    MyQueue q;

    for (int i = 0; i < k; i++)
        q.push(nums[i]);
    ret.push_back(q.front());

    for (int i = k; i < nums.size(); i++)
    {
        q.pop(nums[i - k]);
        q.push(nums[i]);
        ret.push_back(q.front());
    }

    return ret;
}