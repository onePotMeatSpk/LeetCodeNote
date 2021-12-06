#pragma once
#include<vector>
#include"¶þ²æÊ÷.h"
#include<iostream>
using namespace std;

TreeNode* buildBalancedBSTUsingSortedArrayCore(vector<int>& v, int l, int r) {
	if (l > r)	return NULL;
	TreeNode* root = NULL;
	if (l == r)	root = new TreeNode(v[r]);
	int mid = l + (r - l) / 2;
	root = new TreeNode(v[mid]);
	root->left = buildBalancedBSTUsingSortedArrayCore(v, l, mid - 1);
	root->right = buildBalancedBSTUsingSortedArrayCore(v, mid + 1, r);
	return root;
}

TreeNode* buildBalancedBSTUsingSortedArray(vector<int>& v) {
	return buildBalancedBSTUsingSortedArrayCore(v,0,v.size()-1);
}