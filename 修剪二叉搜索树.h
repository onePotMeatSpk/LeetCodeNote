#pragma once
#include"¶þ²æÊ÷.h"

TreeNode* emptyBST(TreeNode* root)
{
    if (!root)   return NULL;
    root->left = emptyBST(root->left);
    root->right = emptyBST(root->right);
    delete root;
    return NULL;
}

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root)   return NULL;

    if (root->val < low)
    {
        root->left = emptyBST(root->left);
        TreeNode* temp = root->right;
        delete(root);
        return trimBST(temp, low, high);
    }
    else if (root->val > high)
    {
        root->right = emptyBST(root->right);
        TreeNode* temp = root->left;
        delete(root);
        return trimBST(temp, low, high);
    }

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}