#pragma once
#include"二叉树.h"
using namespace std;
//力扣106
//题目：从中序与后序遍历序列构造二叉树
//题目描述：给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。


TreeNode* dfsBuildTree(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int posL, int posR) {
    if (inL > inR)   return NULL;

    TreeNode* root = new TreeNode(postorder[posR]);
    int i;
    for (i = inL; i <= inR; i++)
        if (inorder[i] == postorder[posR])   break;

    int lenL = i - inL, lenR = inR - i;

    root->left = dfsBuildTree(inorder, postorder, inL, inL + lenL - 1, posL, posL + lenL - 1);
    root->right = dfsBuildTree(inorder, postorder, inR - lenR + 1, inR, posR - lenR, posR - 1);

    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return dfsBuildTree(inorder, postorder, 0, inorder.size() - 1, 0, inorder.size() - 1);
}