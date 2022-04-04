#pragma once
#include<vector>
#include"������.h"
#include"��������.h"
#include<iostream>
using namespace std;

TreeNode* sortedArrayToBSTCore(vector<int>& v, int l, int r) {
	if (l > r)	return NULL;
	//if (l == r)	root = new TreeNode(v[r]);
	int mid = l + (r - l) / 2;
	TreeNode*  root = new TreeNode(v[mid]);
	root->left = sortedArrayToBSTCore(v, l, mid - 1);
	root->right = sortedArrayToBSTCore(v, mid + 1, r);
	return root;
}

//��������ת��ΪBST
TreeNode* sortedArrayToBST(vector<int>& v) {
	return sortedArrayToBSTCore(v,0,v.size()-1);
}


////������������ת��ΪBST
TreeNode* sortedListToBST(ListNode* head) {
	vector<int> v;
	for (ListNode* p = head; p != NULL; p = p->next)
		v.push_back(p->val);
	return sortedArrayToBST(v);
}