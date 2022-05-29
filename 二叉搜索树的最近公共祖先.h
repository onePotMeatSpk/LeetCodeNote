#pragma once
#include"二叉树.h"
//力扣235
//题目：二叉搜索树的最近公共祖先
//题目描述：给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

//普通二叉搜索树，必须使用中序遍历，进行回溯，效率很低
//BST，左子树皆小于根，右子树皆大于根，故而可用二分法
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root)
    {
        //root值，若处于p、q值的中间，则root必为最近公共祖先
        if (root->val >= p->val && root->val <= q->val)  return root;
        if (root->val <= p->val && root->val >= q->val)  return root;

        //root值，若处于p、q值的一边，则需要向另一边遍历
        if (root->val < p->val && root->val < q->val) {
            root = root->right;
            continue;
        }
        if (root->val > p->val && root->val > q->val) {
            root = root->left;
            continue;
        }
    }

    return NULL;
}