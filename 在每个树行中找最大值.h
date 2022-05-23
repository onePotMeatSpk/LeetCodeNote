#pragma once
#include<queue>
#include<vector>
#include"二叉树.h"
using namespace std;
//力扣515
//题目：在每个树行中找最大值
//题目描述：给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

vector<int> largestValues(TreeNode* root) {
    vector<int> v;
    if (!root)   return v;
    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        int maxNum = INT_MIN;
        while (count--)
        {
            TreeNode* temp = q.front();
            q.pop();
            maxNum = maxNum > temp->val ? maxNum : temp->val;
            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        v.push_back(maxNum);
    }

    return v;
}