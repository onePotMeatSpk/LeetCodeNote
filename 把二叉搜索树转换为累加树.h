#pragma once
#include"二叉树.h"
//力扣538
//题目：把二叉搜索树转换为累加树
// 题目描述:给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的
//			新值等于原树中大于或等于 node.val 的值之和。


// 解题思路：中序遍历，但是反着来，先右再左


//方法1：中序递归
void dfsConvertBST(TreeNode* root, int& sum) {
    if (!root)   return;

    dfsConvertBST(root->right, sum);

    sum += root->val;
    root->val = sum;

    dfsConvertBST(root->left, sum);
}

TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    dfsConvertBST(root, sum);
    return root;
}


//方法2：中序迭代
TreeNode* convertBST(TreeNode* root) {
    if (!root)   return NULL;

    int sum = 0;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.pop();

            if (temp->left)  s.push(temp->left);

            s.push(temp);
            s.push(NULL);

            if (temp->right) s.push(temp->right);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            sum += temp->val;
            temp->val = sum;
        }
    }

    return root;
}