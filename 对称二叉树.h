#pragma once
#include"二叉树.h"

//力扣101
//题目：对称二叉树
//题目描述：给你一个二叉树的根节点 root ， 检查它是否轴对称


//方法1：后序递归
bool isSymmetricCore(TreeNode* root0, TreeNode* root1)
{
    //先判断当前两个节点是否相等
    if ((!root0) && (!root1))    return 1;
    if ((!root0) || (!root1))  return 0;
    if (root0->val != root1->val)    return 0;

    //再判断以这俩节点为根的俩二叉树是否对称
    return isSymmetricCore(root0->left, root1->right) && isSymmetricCore(root0->right, root1->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root)   return 1;
    return isSymmetricCore(root->left, root->right);
}


//方法2：栈迭代
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


//方法3：队列迭代
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