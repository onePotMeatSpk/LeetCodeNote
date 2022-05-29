#pragma once
#include"������.h"
//����530
//��Ŀ����������������С���Բ�
// ��Ŀ����������һ�������������ĸ��ڵ� root ������ ������������ͬ�ڵ�ֵ֮�����С��ֵ ����ֵ��һ������������ֵ������ֵ
//			֮��ľ���ֵ��

//˼·������������������������Ϊ˳�����֣���ô�������ڵ�ľ��Բ������С�ģ��������Ҿ�����

//����1������ݹ�
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

//����2���������
int getMinimumDifference(TreeNode* root) {
    int pre = 0, diff = INT_MAX;//pre��ǰ�ڵ��ֵ��diff��¼Ŀǰ����С���Բ�
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