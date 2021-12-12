#pragma once
#include<vector>
#include<iostream>
#include"二叉树.h"
using namespace std;

TreeNode* rebuildTreeWithPreAndInOrder(vector<int>& preorder,int preL,int preR,
									   vector<int>& inorder,int inL,int inR) {
	if (preL > preR)	return NULL;
	//创建根节点
	int valRoot = preorder[preL];
	TreeNode* root = new TreeNode(valRoot);
	//找到根节点在中序数组中的位置，并得到左右子树的范围大小
	int mid = 0;
	for(int i =inL;i<=inR;i++)
		if (inorder[i] == valRoot)
		{
			mid = i;
			break;
		}
	int rangeL = mid - inL;
	int rangeR = inR - mid;
	//递归构建左右子树
	root->left = rebuildTreeWithPreAndInOrder(preorder, preL + 1, preL + rangeL, inorder, inL, inL + rangeL - 1);
	root->right = rebuildTreeWithPreAndInOrder(preorder, preR - rangeR + 1, preR, inorder, inR - rangeR + 1, inR);
	//返回
	return root;
}


TreeNode* rebuildTreeWithPreAndIn(vector<int>& preorder, vector<int>& inorder) {
	int len = preorder.size();
	if (len == 0)	return NULL;
	return rebuildTreeWithPreAndInOrder(preorder, 0, len - 1, inorder, 0, len - 1);
}
