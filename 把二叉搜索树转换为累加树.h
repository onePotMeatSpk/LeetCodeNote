#pragma once
#include"二叉树.h"
//题目：把二叉搜索树转换为累加树
// 题目描述:给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的
//			新值等于原树中大于或等于 node.val 的值之和。
// 
// 解题思路：中序遍历，但是反着来，先右再左
void convertBSTCore(TreeNode* root, int& sum) {
    if (!root)   return;
    convertBSTCore(root->right, sum);
    sum += root->val;
    root->val = sum;
    convertBSTCore(root->left, sum);
}
TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    convertBSTCore(root, sum);
    return root;
}