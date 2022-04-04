#pragma once
#include"二叉树.h"
//题目：所有左叶子之和
//题目描述：给定二叉树的根节点 root ，返回所有左叶子之和。

//辅助函数（基于前序遍历）
//root为要遍历的子树
//flagIsLeft标志该子树是否为左子树，是为true，不是为false
//返回root中所有左叶子的和
int sumOfLeftLeavesCore(TreeNode* root, bool flagIsLeft) {
    //鲁棒
    if (!root)   return 0;

    //是叶子节点，接着判断是不是左叶子
    if (!root->left && !root->right) return flagIsLeft ? root->val : 0;

    //不是叶子节点，那么root的左叶子之和就只取决于子树了
    int count = 0;
    count += root->left ? sumOfLeftLeavesCore(root->left, 1) : 0;
    count += root->right ? sumOfLeftLeavesCore(root->right, 0) : 0;
    return  count;
}

int sumOfLeftLeaves(TreeNode* root) {
    return sumOfLeftLeavesCore(root, 0);
}