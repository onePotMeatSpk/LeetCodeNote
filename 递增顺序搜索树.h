#pragma once
#include"二叉树.h"
//题目：递增顺序搜索树
// 题目描述：给你一棵二叉搜索树的 root ，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。

void increasingBSTCore(TreeNode* root, TreeNode*& prev,TreeNode*& head) {
	if (!root)	return;
	increasingBSTCore(root->left, prev, head);
	if (!prev)	head = root;
	if (prev)
	{
		prev->right = root;
		root->left = NULL;
	}
	prev = root;
	increasingBSTCore(root->right, prev, head);
}

TreeNode* increasingBST(TreeNode* root) {
	TreeNode* prev = NULL;
	TreeNode* head = NULL;
	increasingBSTCore(root, prev, head);
	return head;
}