#pragma once
#include"二叉树.h"

//题目：两数之和 IV - 输入 BST
//题目描述：给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

TreeNode* isExist(TreeNode* root, int k)
{
    while (root)
    {
        if (k == root->val)  return root;
        if (k < root->val)
        {
            root = root->left;
            continue;
        }
        if (k > root->val)
        {
            root = root->right;
            continue;
        }
    }
    return NULL;
}
bool findTargetCore(TreeNode* root, int& k, TreeNode*& head) {
    if (!root)   return 0;
    if (findTargetCore(root->left, k, head))   return 1;
    TreeNode* t = isExist(head, k - root->val);
    if (t && t != root)    return 1;//一定要辨别查到的是否为本身，如果是本身的话一定不能返回1
    if (findTargetCore(root->right, k, head))   return 1;
    return 0;
}
bool findTarget(TreeNode* root, int k) {
    TreeNode* head = root;
    return findTargetCore(root, k, head);
}