#pragma once
#include"二叉树.h"
//题目：二叉树的直径
//题目描述：给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。


//diameter存放直径
//返回值为root树的深度
int diameterOfBinaryTreeCore(TreeNode* root, int& diameter)
{
    if (!root)  return 0;

    int leftDepth = diameterOfBinaryTreeCore(root->left, diameter);
    int rightDepth = diameterOfBinaryTreeCore(root->right, diameter);

    diameter = max(leftDepth + rightDepth, diameter);//遇到更大的直径时就替换

    return max(leftDepth, rightDepth) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    diameterOfBinaryTreeCore(root, diameter);
    return diameter;
}