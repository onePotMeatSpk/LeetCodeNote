#pragma once
#include"������.h"
//����404
//��Ŀ����Ҷ��֮��
//��Ŀ�����������������ĸ��ڵ� root ������������Ҷ��֮�͡�

//dfs����
int sumOfLeftLeaves(TreeNode* root) {
    if (!root)   return 0;
    if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}