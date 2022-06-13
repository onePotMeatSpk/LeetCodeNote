#pragma once
#include<vector>
#include<stack>
using namespace std;

//力扣739
//题目：每日温度
//题目描述：给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指在第 i 天之后，才会有更高的温度。
//			如果气温在这之后都不会升高，请在该位置用 0 来代替。

vector<int> dailyTemperatures(vector<int>& temperatures) {
	vector<int> ret(temperatures.size(), 0);
	stack<int> s;
	s.push(0);

	for (int i = 1; i < temperatures.size(); i++)
	{
		if (temperatures[i] <= temperatures[s.top()])
			s.push(i);
		else
		{
			while (!s.empty() && temperatures[i] > temperatures[s.top()])
			{
				ret[s.top()] = i - s.top();
				s.pop();
			}

			s.push(i);
		}
	}

	return ret;
}