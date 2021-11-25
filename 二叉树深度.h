#pragma once
#include<iostream>
#include"二叉树.h"
using namespace std;

/*没什么说的，后序遍历就是了*/
int maxDepth(TreeNode* root) {
	if (root == NULL)	return 0;
	int heightOfLeft = maxDepth(root->left);
	int heightOfRight = maxDepth(root->right);
	return (heightOfLeft > heightOfRight ? heightOfLeft : heightOfRight) + 1;
}