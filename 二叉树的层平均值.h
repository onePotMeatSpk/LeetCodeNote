#pragma once
#include"二叉树.h"

//题目：二叉树的层平均值
//题目描述：给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
//层序遍历，没啥可讲

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> v;
    queue<TreeNode*> q;
    int numNow, numNext, count;
    double sum;

    if (root)
    {
        q.push(root);
        numNext = 1;
    }

    while (numNext)
    {
        numNow = numNext;
        count = numNow;
        numNext = 0;
        sum = 0;

        while (count)
        {
            sum += q.front()->val;
            if (q.front()->left)
            {
                q.push(q.front()->left);
                numNext++;
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
                numNext++;
            }
            q.pop();
            count--;
        }

        v.push_back(sum / numNow);
    }

    return v;
}