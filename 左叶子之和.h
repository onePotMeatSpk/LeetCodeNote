#pragma once
#include"二叉树.h"
//力扣404
//题目：左叶子之和
//题目描述：给定二叉树的根节点 root ，返回所有左叶子之和。

//dfs先序
int sumOfLeftLeaves(TreeNode* root) {
    if (!root)   return 0;
    if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}