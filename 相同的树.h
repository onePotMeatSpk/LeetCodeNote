#pragma once
#include"������.h"
using namespace std;

//����100
//��Ŀ����ͬ����
//��Ŀ�������������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
//			����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

//����1���ݹ�
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q)    return 1;
    if (!p || !q)    return 0;
    if (p->val != q->val)    return 0;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//����2���������
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

            //��ջĳ���ڵ�ʱ������������ӽڵ��������������һ�£���������ͬ
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

            //��ջʱ��������ڵ�ֵ�Ƿ�һ��
            if (temp1->val != temp2->val)    return 0;
        }
    }

    return 1;
}
