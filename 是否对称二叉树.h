#pragma once
#include"二叉树.h"

//题目：是否对称二叉树
//题目描述：给你一个二叉树的根节点 root ， 检查它是否轴对称

bool isSymmetricCore(TreeNode* root0, TreeNode* root1)
{
    //先判断当前两个节点是否相等
    if ((!root0) && (!root1))    return 1;
    if ((!root0) || (!root1))  return 0;
    if (root0->val != root1->val)    return 0;

    //再判断以这俩节点为根的俩二叉树是否对称
    return isSymmetricCore(root0->left, root1->right) && isSymmetricCore(root0->right, root1->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root)   return 1;
    return isSymmetricCore(root->left, root->right);
}