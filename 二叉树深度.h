#pragma once
#include<iostream>
#include"������.h"
using namespace std;

/*ûʲô˵�ģ��������������*/
int maxDepth(TreeNode* root) {
	if (root == NULL)	return 0;
	int heightOfLeft = maxDepth(root->left);
	int heightOfRight = maxDepth(root->right);
	return (heightOfLeft > heightOfRight ? heightOfLeft : heightOfRight) + 1;
}