#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;


int maximalRectangle(vector<string>& matrix) {
	//³��
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
	//����ά
	for (i = 0; i < rows; i++)
	{
		//�����н�ά
		for (j = 0; j < cols; j++)
			vectorOneD[j] = (matrix[i][j] == '0') ? 0 : (vectorOneD[j] + 1);

		//��ջ�����쵥������ջ
		for (j = 0; j < cols; j++)
		{
			//��֤��������ջ
			while ((!stackOneD.empty()) && (vectorOneD[j] < vectorOneD[stackOneD.top()]))
			{
				//��ǰ����߶�
				height = vectorOneD[stackOneD.top()];
				stackOneD.pop();
				while ((!stackOneD.empty()) && (vectorOneD[stackOneD.top()] == height))
					stackOneD.pop();
				//����������
				if (stackOneD.empty())
					area = j * height;
				else
					area = (j - (stackOneD.top() + 1)) * height;
				maxArea = (maxArea < area) ? area : maxArea;
			}
			//��ջ�¾���
			stackOneD.push(j);
		}

		//��ջ
		while (!stackOneD.empty())
		{
			//��ǰ����߶�
			height = vectorOneD[stackOneD.top()];
			stackOneD.pop();
			while ((!stackOneD.empty()) && (vectorOneD[stackOneD.top()] == height))
				stackOneD.pop();
			//����������
			if (stackOneD.empty())
				area = cols * height;
			else
				area = (cols - (stackOneD.top() + 1)) * height;
			maxArea = (maxArea < area) ? area : maxArea;
		}
	}

	return maxArea;
}