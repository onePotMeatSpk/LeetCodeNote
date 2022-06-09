#pragma once
#include<queue>
#include<vector>
#include"二叉树.h"
using namespace std;

//实现方式1：迭代
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



//实现方式2：递归

//先序递归函数
void dfs(TreeNode* root, vector<vector<int>>& vAll, int depth = 0)
{
	if (!root)	return;

	if (vAll.size() < depth + 1)	vAll.push_back(vector<int>());

	vAll[depth].push_back(root->val);

	dfs(root->left, vAll, depth + 1);
	dfs(root->right, vAll, depth + 1);
}

//主函数
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> vAll;
	dfs(root, vAll);
	return vAll;
}