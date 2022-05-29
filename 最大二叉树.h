#pragma once
#include"二叉树.h"
using namespace std;
//力扣654
//题目：最大二叉树
//题目描述：给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
            //创建一个根节点，其值为 nums 中的最大值。
            //递归地在最大值 左边 的 子数组前缀上 构建左子树。
            //递归地在最大值 右边 的 子数组后缀上 构建右子树。
            //返回 nums 构建的 最大二叉树 。


TreeNode* dfsConstructMaximumBinaryTree(vector<int>& nums, int l, int r) {
    if (l > r)   return NULL;

    int maxIndex = l;
    for (int i = l; i <= r; i++)
        maxIndex = nums[i] > nums[maxIndex] ? i : maxIndex;
    TreeNode* root = new TreeNode(nums[maxIndex]);

    root->left = dfsConstructMaximumBinaryTree(nums, l, maxIndex - 1);
    root->right = dfsConstructMaximumBinaryTree(nums, maxIndex + 1, r);
    return root;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return dfsConstructMaximumBinaryTree(nums, 0, nums.size() - 1);
}
