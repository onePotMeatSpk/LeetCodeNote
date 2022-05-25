#pragma once
#include"二叉树.h"
using namespace std;

//力扣100
//题目：相同的树
//题目描述：给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//			如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

//方法1：递归
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q)    return 1;
    if (!p || !q)    return 0;
    if (p->val != q->val)    return 0;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//方法2：先序迭代
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q)    return 1;
    if (!p || !q)    return 0;
    if (p->val != q->val)    return 0;

    stack<TreeNode*> s1, s2;
    s1.push(p);
    s2.push(q);
    while (!s1.empty() && !s2.empty())
    {
        TreeNode* temp1 = s1.top();
        TreeNode* temp2 = s2.top();
        if (temp1)
        {
            s1.pop();
            s2.pop();

            //入栈某两节点时，考检查他们子节点存在情况，如果不一致，则两树不同
            if (temp1->left && !temp2->left || !temp1->left && temp2->left)  return 0;
            if (temp1->right && !temp2->right || !temp1->right && temp2->right)  return 0;

            if (temp1->left) s1.push(temp1->left);
            if (temp1->right) s1.push(temp1->right);
            if (temp2->left) s2.push(temp2->left);
            if (temp2->right) s2.push(temp2->right);

            s1.push(temp1);
            s1.push(NULL);
            s2.push(temp2);
            s2.push(NULL);
        }
        else
        {
            s1.pop();
            temp1 = s1.top();
            s1.pop();
            s2.pop();
            temp2 = s2.top();
            s2.pop();

            //出栈时，检查两节点值是否一致
            if (temp1->val != temp2->val)    return 0;
        }
    }

    return 1;
}
