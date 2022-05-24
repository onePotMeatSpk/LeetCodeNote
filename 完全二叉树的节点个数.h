#pragma once
#include"二叉树.h"
using namespace std;

//力扣222
//题目：完全二叉树的节点个数
//题目描述：给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 
//!!!进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？

//满二叉树的节点个数是2^depth - 1，完全二叉树中必然有满二叉树，故而可以利用这些满二叉树，来降低时间复杂度
//在每个节点处，判断以其为根的树是否满二叉树，如果是满二叉树，那么其左右边的高度一定相等
//根据是否满二叉树，来选择计算节点数量的方法：
//      是：2^depth - 1
//      否：左子树节点数量 + 右子树节点数量 + 1
int countNodes(TreeNode* root) {
    if (!root)   return 0;

    //计算左右边的高度
    int depthL = 0, depthR = 0;
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    while (l)
    {
        depthL++;
        l = l->left;
    }
    while (r)
    {
        depthR++;
        r = r->right;
    }

    //计算节点数量
    //如果左右边高度相等，则是满二叉树，可以使用公式
    if (depthL == depthR)    return pow(2, depthL + 1) - 1;
    //否则非满二叉树，需要左右子树相加，再加1
    else    return countNodes(root->left) + countNodes(root->right) + 1;
}