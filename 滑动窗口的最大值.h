#pragma once
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void push_new(int value, deque<int>& deq)
{
	if (value > deq.front())
	{
		deq.clear();
		deq.push_back(value);
		return;
	}

	while (1)
	{
		if (value <= deq.back())
		{
			deq.push_back(value);
			return;
		}
		else
			deq.pop_back();
	}
}

void pop_old(int value, deque<int>& deq)
{
	if (value == deq.front())
		deq.pop_front();
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	deque<int>dequeSlidingWindow;
	vector<int>vectorMaxNums;
	int left = 0, right = k;

	//鲁棒性
	if (nums.size() < k)
		return vectorMaxNums;
	if(nums.empty())
		return vectorMaxNums;
	if (k == 0)
		return vectorMaxNums;

	//初始化单调列表
	if (dequeSlidingWindow.empty())
		dequeSlidingWindow.push_back(nums[0]);
	for (int i = 1; i < k; i++)
		push_new(nums[i], dequeSlidingWindow);
	vectorMaxNums.push_back(dequeSlidingWindow.front());

	//更新单调列表和返回数组
	while (right < nums.size())
	{
		push_new(nums[right++], dequeSlidingWindow);
		pop_old(nums[left++], dequeSlidingWindow);
		vectorMaxNums.push_back(dequeSlidingWindow.front());
	}

	return vectorMaxNums;
}