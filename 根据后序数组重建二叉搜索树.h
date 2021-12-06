#pragma once
#include<vector>
#include"¶þ²æÊ÷.h"
#include<iostream>
using namespace std;


TreeNode* rebuildBSTUsingPostTraverseCore(vector<int>& v, int l, int r) {
	if (r < l)	return NULL;
	TreeNode* root = new TreeNode(v[r]);
	if (l == r)	return root;

	int mid = r - 1;
	while ((mid >= l) && (v[mid] > v[r]))	--mid;

	root->left = rebuildBSTUsingPostTraverseCore(v, l, mid);
	root->right = rebuildBSTUsingPostTraverseCore(v, mid + 1, r - 1);

	return root;
}

TreeNode* rebuildBSTUsingPostTraverse(vector<int>& v) {
	return rebuildBSTUsingPostTraverseCore(v, 0, v.size() - 1);
}