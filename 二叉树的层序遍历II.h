#pragma once
#include<queue>
#include<vector>
#include"二叉树.h"
using namespace std;
//力扣107
//题目：二叉树的层序遍历II
//题目描述：给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

//在普通层序遍历的基础上，加个栈
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