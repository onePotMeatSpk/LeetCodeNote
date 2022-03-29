#pragma once
#include"������.h"

//��Ŀ���������Ĳ�ƽ��ֵ
//��Ŀ����������һ���ǿն������ĸ��ڵ� root , ���������ʽ����ÿһ��ڵ��ƽ��ֵ����ʵ�ʴ���� 10-5 ���ڵĴ𰸿��Ա����ܡ�
//���������ûɶ�ɽ�

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