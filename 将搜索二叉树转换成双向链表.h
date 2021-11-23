#pragma once
#include<iostream>
#include"������.h"

//��ʵ����������������
void convertCore(TreeNode* root, TreeNode*& pre, TreeNode*& head)
{
	if (!root)	return;
	convertCore(root->left, pre, head);
	if (!pre)	head = root;
	else
	{
		pre->right = root;
		root->left = pre;
	}
	pre = root;
	convertCore(root->right, pre, head);
}

TreeNode* convert(TreeNode* root)
{
	TreeNode* pre = NULL;
	TreeNode* head = NULL;
	convertCore(root, pre, head);
	return head;
}