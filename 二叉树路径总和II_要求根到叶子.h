#pragma once
#include"������.h"
#include<vector>
using namespace std;

//����113
//��Ŀ��������·���ܺ�II_����·��_Ҫ�����Ҷ��
//��Ŀ����������������ĸ��ڵ� root ��һ������Ŀ��� targetSum ���ҳ����� �Ӹ��ڵ㵽Ҷ�ӽڵ� ·���ܺ͵��ڸ���Ŀ��͵�·����

//����1������ݹ����
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


//����2�������������
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> vAll;
    if (!root)   return vAll;
    vector<int> v;
    stack<TreeNode*> s;
    s.push(root);
    int sum = 0;

    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.pop();
            s.push(temp);
            s.push(NULL);
            v.push_back(temp->val);
            sum += temp->val;

            if (temp->left)  s.push(temp->left);
            if (temp->right) s.push(temp->right);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            if (!temp->left && !temp->right)
                if (sum == targetSum)
                    vAll.push_back(v);

            v.pop_back();
            sum -= temp->val;
        }
    }

    return vAll;
}