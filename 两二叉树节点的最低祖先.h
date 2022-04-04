#pragma once
#include"二叉树.h"
//题目：两二叉树节点的最低祖先
//题目描述：给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

//当确定两节点都在树中时，才可以使用该方法
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root)   return NULL;
    if ((root == p) || (root == q))  return root;
    TreeNode* resLeft = lowestCommonAncestor1(root->left, p, q);
    TreeNode* resRight = lowestCommonAncestor1(root->right, p, q);
    if (resLeft && resRight) return root;
    if (resLeft) return resLeft;
    if (resRight)    return resRight;
    return NULL;
}


//该方式适用于不确定两节点都在树中
int lowestCommonAncestor2Core(TreeNode* root, TreeNode*& p, TreeNode*& q, TreeNode*& find)
{
    if (!root)   return 0;
    int l, r, s;
    if ((l = lowestCommonAncestor2Core(root->left, p, q, find)) == 3)   return 3;
    if ((r = lowestCommonAncestor2Core(root->right, p, q, find)) == 3)   return 3;

    s = l + r;

    if (s == 3)
    {
        find = root;
        return 3;
    }

    if (s)
    {
        if ((root == p) || (root == q))
        {
            find = root;
            return 3;
        }
        return s;
    }

    if (root == p)   return 1;
    if (root == q)   return 2;
    return 0;
}
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* find = NULL;
    if (lowestCommonAncestor2Core(root, p, q, find) == 3) return find;
    return NULL;
}
