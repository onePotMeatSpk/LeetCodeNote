#pragma once
#include"������.h"
#include<vector>
using namespace std;

//����113
//��Ŀ��������·���ܺ�2_Ҫ�����Ҷ��
//��Ŀ����������������ĸ��ڵ� root ��һ������Ŀ��� targetSum ���ҳ����� �Ӹ��ڵ㵽Ҷ�ӽڵ� ·���ܺ͵��ڸ���Ŀ��͵�·����

//˼·���������������
//dfs����
void dfsPathSum(TreeNode* root, const int& targetSum, vector<vector<int>>& vAll, vector<int>& v, int sum = 0) {
	//³��
	if (!root)   return;
	//����Ҷ�ӽڵ�
	if (!root->left && !root->right)
	{
		if (sum + root->val == targetSum)
		{
			v.push_back(root->val);
			vAll.push_back(v);
			v.pop_back();
		}	
		return;
	}

	v.push_back(root->val);
	dfsPathSum(root->left, targetSum, vAll, v, sum + root->val);
	dfsPathSum(root->right, targetSum, vAll, v, sum + root->val);
	v.pop_back();
}

//������
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
	vector<vector<int>> vAll;
	vector<int> v;
	dfsPathSum(root, targetSum, vAll, v);
	return vAll;
}