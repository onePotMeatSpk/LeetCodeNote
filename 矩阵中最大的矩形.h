#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;


int maximalRectangle(vector<string>& matrix) {
	//鲁棒
	int rows = matrix.size();
	if (rows == 0)   return 0;
	int cols = matrix[0].size();
	if (cols == 0)   return 0;


	vector<int> vectorOneD(cols, 0);
	stack<int> stackOneD;
	int height = 0;
	int maxArea = 0;
	int area = 0;
	int i, j;
	//矩阵降维
	for (i = 0; i < rows; i++)
	{
		//逐层进行降维
		for (j = 0; j < cols; j++)
			vectorOneD[j] = (matrix[i][j] == '0') ? 0 : (vectorOneD[j] + 1);

		//入栈：构造单调不减栈
		for (j = 0; j < cols; j++)
		{
			//保证单调不减栈
			while ((!stackOneD.empty()) && (vectorOneD[j] < vectorOneD[stackOneD.top()]))
			{
				//当前矩阵高度
				height = vectorOneD[stackOneD.top()];
				stackOneD.pop();
				while ((!stackOneD.empty()) && (vectorOneD[stackOneD.top()] == height))
					stackOneD.pop();
				//更新最大面积
				if (stackOneD.empty())
					area = j * height;
				else
					area = (j - (stackOneD.top() + 1)) * height;
				maxArea = (maxArea < area) ? area : maxArea;
			}
			//入栈新矩阵
			stackOneD.push(j);
		}

		//出栈
		while (!stackOneD.empty())
		{
			//当前矩阵高度
			height = vectorOneD[stackOneD.top()];
			stackOneD.pop();
			while ((!stackOneD.empty()) && (vectorOneD[stackOneD.top()] == height))
				stackOneD.pop();
			//更新最大面积
			if (stackOneD.empty())
				area = cols * height;
			else
				area = (cols - (stackOneD.top() + 1)) * height;
			maxArea = (maxArea < area) ? area : maxArea;
		}
	}

	return maxArea;
}