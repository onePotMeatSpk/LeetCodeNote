#pragma once
#include<queue>
#include<vector>
#include"二叉树.h"
using namespace std;
//力扣637
//题目：二叉树的层平均值
//题目描述：给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。

//层序遍历，没啥可讲
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> v;
    if (!root)
        return v;
    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty())
    {
        double sum = 0;
        int count = q.size(), num = q.size();
        while (count--)
        {
            TreeNode* temp = q.front();
            q.pop();
            sum += temp->val;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        v.push_back(sum / num);
    }

    return v;
}