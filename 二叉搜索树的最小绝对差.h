#pragma once
#include"二叉树.h"
//题目：二叉搜索树的最小绝对差
// 题目描述：给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。差值是一个正数，其数值等于两值
//			之差的绝对值。

//思路：中序遍历二叉搜索树，结果为顺序数字，那么相邻两节点的绝对差就是最小的，在其中找就是了

void getMinimumDifferenceCore(TreeNode* root, TreeNode*& prev, int& diff)
{
    if (!root)   return;
    getMinimumDifferenceCore(root->left, prev, diff);
    int ab = prev ? abs(root->val - prev->val) : -1;
    diff = ab == -1 ? -1 : (diff == -1 ? ab : (diff > ab ? ab : diff));
    prev = root;
    getMinimumDifferenceCore(root->right, prev, diff);
}
int getMinimumDifference(TreeNode* root) {
    TreeNode* prev = NULL;
    int diff;
    getMinimumDifferenceCore(root, prev, diff);
    return diff;
}