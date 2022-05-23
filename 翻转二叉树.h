#pragma once
#include<queue>
#include"二叉树.h"
using namespace std;
//力扣226
//题目：翻转二叉树
//题目描述：给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

//该题可用前序、后序、层序，唯独不可用中序，因为中序会导致一些节点被反转两次，也就是没有反转

//方法1：后序遍历
// 
//递归实现
TreeNode* invertTreePosRec(TreeNode* root) {
    if (!root)   return root;
    invertTreePosRec(root->left);
    invertTreePosRec(root->right);
    swap(root->left, root->right);
    return root;
}

//迭代实现
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

//方法2：前序遍历
// 
//递归实现
TreeNode* invertTreePreRec(TreeNode* root) {
    if (!root)   return root;
    swap(root->left, root->right);
    invertTreePreRec(root->left);
    invertTreePreRec(root->right);
    return root;
}

//迭代实现
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

//方法3：层序遍历
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