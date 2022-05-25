#pragma once
#include"������.h"
//����404
//��Ŀ����Ҷ��֮��
//��Ŀ�����������������ĸ��ڵ� root ������������Ҷ��֮�͡�

//����1���ݹ�����
int sumOfLeftLeaves(TreeNode* root) {
    if (!root)   return 0;
    if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

//����2�������������򡢺��򡢲���Ҳ���ԣ�
int sumOfLeftLeaves(TreeNode* root) {
    if (!root)   return 0;
    stack<TreeNode*> s;
    s.push(root);
    int sum = 0;
    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.pop();

            if (temp->left)  s.push(temp->left);
            if (temp->right) s.push(temp->right);

            s.push(temp);
            s.push(NULL);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            if (temp->left && !temp->left->left && !temp->left->right)   sum += temp->left->val;
        }
    }

    return sum;
}