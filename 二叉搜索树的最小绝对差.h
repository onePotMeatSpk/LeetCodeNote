#pragma once
#include"二叉树.h"
//力扣530
//题目：二叉搜索树的最小绝对差
// 题目描述：给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。差值是一个正数，其数值等于两值
//			之差的绝对值。

//思路：中序遍历二叉搜索树，结果为顺序数字，那么相邻两节点的绝对差就是最小的，在其中找就是了

//方法1：中序递归
void getMinimumDifferenceCore(TreeNode* root, int& pre, int& diff, bool& flag)
{
    if (!root)   return;
    getMinimumDifferenceCore(root->left, pre, diff, flag);
    if (!flag)
    {
        flag = 1;
        pre = root->val;
    }
    else
    {
        diff = diff < root->val - pre ? diff : root->val - pre;
        pre = root->val;
    }
    
    getMinimumDifferenceCore(root->right, pre, diff, flag);
}
int getMinimumDifference(TreeNode* root) {
    int pre = 0, diff = INT_MAX;
    bool flag = 0;
    getMinimumDifferenceCore(root, pre, diff, flag);
    return diff;
}

//方法2：中序迭代
int getMinimumDifference(TreeNode* root) {
    int pre = 0, diff = INT_MAX;//pre是前节点的值，diff记录目前的最小绝对差
    bool flag = 0;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.pop();

            if (temp->right) s.push(temp->right);
            s.push(temp);
            s.push(NULL);
            if (temp->left)  s.push(temp->left);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            if (!flag)
            {
                flag = 1;
                pre = temp->val;
            }
            else
            {
                diff = temp->val - pre < diff ? temp->val - pre : diff;
                pre = temp->val;
            }
        }
    }

    return diff;
}