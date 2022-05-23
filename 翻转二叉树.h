#pragma once
#include<queue>
#include"������.h"
using namespace std;
//����226
//��Ŀ����ת������
//��Ŀ����������һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣

//�������ǰ�򡢺��򡢲���Ψ��������������Ϊ����ᵼ��һЩ�ڵ㱻��ת���Σ�Ҳ����û�з�ת

//����1���������
// 
//�ݹ�ʵ��
TreeNode* invertTreePosRec(TreeNode* root) {
    if (!root)   return root;
    invertTreePosRec(root->left);
    invertTreePosRec(root->right);
    swap(root->left, root->right);
    return root;
}

//����ʵ��
TreeNode* invertTreePosIte(TreeNode* root) {
    if (!root)   return root;
    stack<TreeNode*> s;

    s.push(root);

    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.pop();

            s.push(temp);
            s.push(NULL);

            if (temp->right) s.push(temp->right);
            if (temp->left)  s.push(temp->left);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();
            swap(temp->left, temp->right);
        }
    }

    return root;
}

//����2��ǰ�����
// 
//�ݹ�ʵ��
TreeNode* invertTreePreRec(TreeNode* root) {
    if (!root)   return root;
    swap(root->left, root->right);
    invertTreePreRec(root->left);
    invertTreePreRec(root->right);
    return root;
}

//����ʵ��
TreeNode* invertTreePreIte(TreeNode* root) {
    if (!root)   return root;
    stack<TreeNode*> s;

    s.push(root);

    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.pop();

            if (temp->right) s.push(temp->right);
            if (temp->left)  s.push(temp->left);

            s.push(temp);
            s.push(NULL);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();
            swap(temp->left, temp->right);
        }
    }

    return root;
}

//����3���������
TreeNode* invertTreeLev(TreeNode* root) {
    if (!root)   return root;
    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            TreeNode* temp = q.front();
            q.pop();

            swap(temp->left, temp->right);

            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    return root;
}