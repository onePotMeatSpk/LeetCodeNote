#pragma once
#include<vector>
#include<iostream>
#include"������.h"
using namespace std;

TreeNode* rebuildTreeWithPreAndInOrder(vector<int>& preorder,int preL,int preR,
									   vector<int>& inorder,int inL,int inR) {
	if (preL > preR)	return NULL;
	//�������ڵ�
	int valRoot = preorder[preL];
	TreeNode* root = new TreeNode(valRoot);
	//�ҵ����ڵ������������е�λ�ã����õ����������ķ�Χ��С
	int mid = 0;
	for(int i =inL;i<=inR;i++)
		if (inorder[i] == valRoot)
		{
			mid = i;
			break;
		}
	int rangeL = mid - inL;
	int rangeR = inR - mid;
	//�ݹ鹹����������
	root->left = rebuildTreeWithPreAndInOrder(preorder, preL + 1, preL + rangeL, inorder, inL, inL + rangeL - 1);
	root->right = rebuildTreeWithPreAndInOrder(preorder, preR - rangeR + 1, preR, inorder, inR - rangeR + 1, inR);
	//����
	return root;
}


TreeNode* rebuildTreeWithPreAndIn(vector<int>& preorder, vector<int>& inorder) {
	int len = preorder.size();
	if (len == 0)	return NULL;
	return rebuildTreeWithPreAndInOrder(preorder, 0, len - 1, inorder, 0, len - 1);
}
