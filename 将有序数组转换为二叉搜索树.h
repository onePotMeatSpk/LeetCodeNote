#pragma once
#include"二叉树.h"
//力扣108
//题目：将有序数组转换为二叉搜索树
//题目描述：给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。


//思路：取数组中点为根，左为左子树，右为右子树

//方法1：递归
TreeNode* dfsSortedArrayToBST(vector<int>& nums, int l, int r) {
    if (l > r)   return NULL;

    int m = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[m]);
    root->left = dfsSortedArrayToBST(nums, l, m - 1);
    root->right = dfsSortedArrayToBST(nums, m + 1, r);

    return root;

}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfsSortedArrayToBST(nums, 0, nums.size() - 1);
}