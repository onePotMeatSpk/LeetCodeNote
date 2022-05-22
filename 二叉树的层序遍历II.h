#pragma once
#include<queue>
#include<vector>
#include"������.h"
using namespace std;
//����107
//��Ŀ���������Ĳ������II
//��Ŀ����������������ĸ��ڵ� root ��������ڵ�ֵ �Ե����ϵĲ������ �� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����

//����ͨ��������Ļ����ϣ��Ӹ�ջ
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> vAll;
	if (!root)	return vAll;
	vector<int> v;
	stack<vector<int>> s;
	queue<TreeNode*> q;

	q.push(root);

	while (!q.empty())
	{
		int count = q.size();
		while (count--)
		{
			TreeNode* temp = q.front();
			q.pop();
			v.push_back(temp->val);

			if (temp->left)	q.push(temp->left);
			if (temp->right)	q.push(temp->right);
		}

		s.push(v);
		v.clear();
	}

	while (!s.empty())
	{
		vAll.push_back(s.top());
		s.pop();
	}

	return vAll;
}