#pragma once
#include<queue>
#include<vector>
#include"������.h"
using namespace std;
//���������ûɶ��˵��
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> vAll;
	if (!root)	return vAll;
	vector<int> v;
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

		vAll.push_back(v);
		v.clear();
	}

	return vAll;
}