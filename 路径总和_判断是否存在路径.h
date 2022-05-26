#pragma once
#include"二叉树.h"

//力扣112
//题目：路径总和_判断是否存在路径
//题目描述：给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，
//			这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

//方法1：后序递归
//辅函数：dfs
bool dfsHasPathSum(TreeNode* root, const int& targetSum, int sum = 0) {
    if (!root)   return 0;
    if (!root->left && !root->right) return sum + root->val == targetSum;
    return dfsHasPathSum(root->left, targetSum, sum + root->val) || dfsHasPathSum(root->right, targetSum, sum + root->val);
}
//主函数
bool hasPathSum(TreeNode* root, int targetSum) {
    return dfsHasPathSum(root, targetSum);
}

//方法2：后序迭代
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root)   return 0;
    stack<TreeNode*> s;
    s.push(root);
    int sum = 0;

    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.push(NULL);
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
                if (sum == targetSum)    return 1;

            sum -= temp->val;
        }
    }

    return 0;
}