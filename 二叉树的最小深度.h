#pragma once
#include"二叉树.h"
#include<queue>
using namespace std;
//力扣111
//题目：二叉树的最小深度
//题目描述：给定一个二叉树，找出其最小深度。
			//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
			//说明 : 叶子节点是指没有子节点的节点。

//方法1：后序递归
int minDepth(TreeNode* root) {
	if (!root)	return 0;//鲁棒

	if (!root->left && !root->right)	return 1;//这才是递归终止条件

	int depth = INT_MAX;
	if (root->left)	depth = min(depth, minDepth(root->left));
	if (root->right)	depth = min(depth, minDepth(root->right));

	return depth + 1;
}

//方法2：层序遍历
int minDepth(TreeNode* root) {
	if (root == NULL)	return 0;

	queue<TreeNode*> q;
	q.push(root);

	int depth = 0;

	while (!q.empty())
	{
		depth++;
		int count = q.size();
		while (count--)
		{
			TreeNode* temp = q.front();
			q.pop();
			
			if (!temp->left && !temp->right)	return depth;//遇到第一个叶子结点，就返回当前深度

			if (temp->left)	q.push(temp->left);
			if (temp->right)	q.push(temp->right);
		}
	}

	return depth;
}
