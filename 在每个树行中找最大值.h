#pragma once
#include<queue>
#include<vector>
#include"������.h"
using namespace std;
//����515
//��Ŀ����ÿ�������������ֵ
//��Ŀ����������һ�ö������ĸ��ڵ� root �����ҳ��ö�������ÿһ������ֵ��

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