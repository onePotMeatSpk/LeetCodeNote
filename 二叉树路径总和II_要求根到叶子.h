#pragma once
#include"二叉树.h"
#include<vector>
using namespace std;

//力扣113
//题目：二叉树路径总和II_所有路径_要求根到叶子
//题目描述：给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

//方法1：先序递归回溯
//dfs函数
void dfsPathSum(TreeNode* root, const int& targetSum, vector<vector<int>>& vAll, vector<int>& v, int sum = 0) {
	//鲁棒
	if (!root)   return;
	//到达叶子节点
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

//主函数
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
	vector<vector<int>> vAll;
	vector<int> v;
	dfsPathSum(root, targetSum, vAll, v);
	return vAll;
}


//方法2：后序迭代回溯
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