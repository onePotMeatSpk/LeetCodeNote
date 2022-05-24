#pragma once
#include"二叉树.h"
#include<queue>
using namespace std;

//力扣104
//题目：二叉树的最大深度
//题目描述：给定一个二叉树，找出其最大深度。
			//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
			//说明 : 叶子节点是指没有子节点的节点。

//方法1：后序递归
int maxDepth(TreeNode* root) {
	if (root == NULL)	return 0;
	int heightOfLeft = maxDepth(root->left);
	int heightOfRight = maxDepth(root->right);
	return max(heightOfLeft, heightOfRight) + 1;
}

//方法2：层序遍历
int maxDepth(TreeNode* root) {
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

			if (temp->left)	q.push(temp->left);
			if (temp->right)	q.push(temp->right);
		}
	}

	return depth;
}
