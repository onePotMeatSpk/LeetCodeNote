#pragma once
#include"二叉树.h"
//力扣404
//题目：左叶子之和
//题目描述：给定二叉树的根节点 root ，返回所有左叶子之和。

//方法1：递归先序
int sumOfLeftLeaves(TreeNode* root) {
    if (!root)   return 0;
    if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

//方法2：迭代先序（中序、后序、层序也可以）
int sumOfLeftLeaves(TreeNode* root) {
    if (!root)   return 0;
    stack<TreeNode*> s;
    s.push(root);
    int sum = 0;
    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.pop();

            if (temp->left)  s.push(temp->left);
            if (temp->right) s.push(temp->right);

            s.push(temp);
            s.push(NULL);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            if (temp->left && !temp->left->left && !temp->left->right)   sum += temp->left->val;
        }
    }

    return sum;
}