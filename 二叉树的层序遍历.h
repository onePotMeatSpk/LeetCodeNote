#pragma once
#include<queue>
#include<vector>
#include"������.h"
using namespace std;

//ʵ�ַ�ʽ1������
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



//ʵ�ַ�ʽ2���ݹ�

//����ݹ麯��
void dfs(TreeNode* root, vector<vector<int>>& vAll, int depth = 0)
{
	if (!root)	return;

	if (vAll.size() < depth + 1)	vAll.push_back(vector<int>());

	vAll[depth].push_back(root->val);

	dfs(root->left, vAll, depth + 1);
	dfs(root->right, vAll, depth + 1);
}

//������
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> vAll;
	dfs(root, vAll);
	return vAll;
}