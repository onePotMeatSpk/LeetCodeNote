#pragma once
#include<queue>
#include<vector>
#include"二叉树.h"
using namespace std;
//力扣199
//题目：二叉树的右视图
//题目描述：给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

//在普通层序遍历的基础上，将每层的队列的最后一个元素（也就是count为0时），推入vector中
vector<int> rightSideView(TreeNode* root) {
	vector<int> vRet;
	if (!root)	return vRet;
	queue<TreeNode*> q;

	q.push(root);

	while (!q.empty())
	{
		int count = q.size();
		while (count--)
		{
			TreeNode* temp = q.front();
			q.pop();
			if (!count)
				vRet.push_back(temp->val);

			if (temp->left)	q.push(temp->left);
			if (temp->right)	q.push(temp->right);
		}
	}

	return vRet;
}