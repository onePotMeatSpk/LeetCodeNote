#pragma once
#include"二叉树.h"
using namespace std;
//力扣654
//题目：合并二叉树
//题目描述：给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
            //创建一个根节点，其值为 nums 中的最大值。
            //递归地在最大值 左边 的 子数组前缀上 构建左子树。
            //递归地在最大值 右边 的 子数组后缀上 构建右子树。
            //返回 nums 构建的 最大二叉树 。、


TreeNode* copyTrees(TreeNode* root) {
    if (!root)   return NULL;
    TreeNode* newRoot = new TreeNode(root->val);
    newRoot->left = copyTrees(root->left);
    newRoot->right = copyTrees(root->right);
    return newRoot;
}
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)    return NULL;

    if (!root1)  return copyTrees(root2);
    if (!root2)  return copyTrees(root1);

    TreeNode* newRoot = new TreeNode(root1->val + root2->val);
    newRoot->left = mergeTrees(root1->left, root2->left);
    newRoot->right = mergeTrees(root1->right, root2->right);
    return newRoot;
}
