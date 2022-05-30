#pragma once
#include"二叉树.h"
//力扣701
//题目：二叉搜索树中的插入操作
//题目描述：给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

//思路：BST一定可以二分

//方法1：递归
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root)   return new TreeNode(val);

    if (root->val == val)    return root;
    if (root->val < val) root->right = insertIntoBST(root->right, val);
    else if (root->val > val) root->left = insertIntoBST(root->left, val);

    return root;
}



//方法2：迭代
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* cur = root;
    while (cur)
    {
        if (cur->val == val) return root;
        if (cur->val < val)
        {
            if (!cur->right)
            {
                cur->right = new TreeNode(val);
                return root;
            }
            cur = cur->right;
        }
        else if (cur->val > val)
        {
            if (!cur->left)
            {
                cur->left = new TreeNode(val);
                return root;
            }
            cur = cur->left;
        }
    }

    return new TreeNode(val);
}