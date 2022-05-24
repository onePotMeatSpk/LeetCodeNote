#pragma once
#include"������.h"

//����101
//��Ŀ���Գƶ�����
//��Ŀ����������һ���������ĸ��ڵ� root �� ������Ƿ���Գ�


//����1������ݹ�
bool isSymmetricCore(TreeNode* root0, TreeNode* root1)
{
    //���жϵ�ǰ�����ڵ��Ƿ����
    if ((!root0) && (!root1))    return 1;
    if ((!root0) || (!root1))  return 0;
    if (root0->val != root1->val)    return 0;

    //���ж��������ڵ�Ϊ�������������Ƿ�Գ�
    return isSymmetricCore(root0->left, root1->right) && isSymmetricCore(root0->right, root1->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root)   return 1;
    return isSymmetricCore(root->left, root->right);
}


//����2��ջ����
bool isSymmetric(TreeNode* root) {
    if (!root)   return 1;
    stack<TreeNode*> s;

    s.push(root->left);
    s.push(root->right);

    while (!s.empty())
    {
        TreeNode* temp1 = s.top();
        s.pop();
        TreeNode* temp2 = s.top();
        s.pop();

        if (!temp1 && !temp2)    continue;
        if (!temp1 || !temp2)    return 0;
        if (temp1->val != temp2->val)    return 0;

        s.push(temp1->left);
        s.push(temp2->right);
        s.push(temp1->right);
        s.push(temp2->left);
    }

    return 1;
}


//����3�����е���
bool isSymmetric(TreeNode* root) {
    if (!root)   return 1;
    queue<TreeNode*> q;

    q.push(root->left);
    q.push(root->right);

    while (!q.empty())
    {
        TreeNode* temp1 = q.front();
        q.pop();
        TreeNode* temp2 = q.front();
        q.pop();

        if (!temp1 && !temp2)    continue;
        if (!temp1 || !temp2)    return 0;
        if (temp1->val != temp2->val)    return 0;

        q.push(temp1->left);
        q.push(temp2->right);
        q.push(temp1->right);
        q.push(temp2->left);
    }

    return 1;
}