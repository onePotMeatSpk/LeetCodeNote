#pragma once
#include<queue>
#include<vector>
#include"������.h"
using namespace std;
//����637
//��Ŀ���������Ĳ�ƽ��ֵ
//��Ŀ����������һ���ǿն������ĸ��ڵ� root , ���������ʽ����ÿһ��ڵ��ƽ��ֵ����ʵ�ʴ���� 10-5 ���ڵĴ𰸿��Ա����ܡ�

//���������ûɶ�ɽ�
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