#pragma once
#include"������.h"
#include<stack>
using namespace std;

//����98
//��Ŀ����֤����������
//��Ŀ����������һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������
			//��Ч �����������������£�
			//
			//�ڵ��������ֻ���� С�� ��ǰ�ڵ������
			//�ڵ��������ֻ���� ���� ��ǰ�ڵ������
			//�������������������������Ҳ�Ƕ�����������


//˼·���������������ô�ֵС�ڵ���ǰ�ڵ�ֵ����˵������BST

//����1������ݹ�
//pre��ǰ�ڵ��ֵ
//flag����ʾǰ���Ƿ��нڵ㣬�ڱ��������·��ڵ�ʱ��1���˺�Ľڵ�ſ��Կ�ʼ��pre�Ƚ�
bool dfsIsValidBST(TreeNode* root, int& pre, bool& flag) {
    if (!root)   return 1;

    if (!dfsIsValidBST(root->left, pre, flag))    return 0;

    if (flag == 0)
    {
        pre = root->val;
        flag = 1;
    }
    else
    {
        if (pre >= root->val)    return 0;//�������������ô�ֵС�ڵ���ǰ�ڵ�ֵ����˵������BST
        else pre = root->val;
    }

    if (!dfsIsValidBST(root->right, pre, flag))    return 0;
    return 1;
}


bool isValidBST(TreeNode* root) {
    int pre = 0;
    bool flag = 0;
    return dfsIsValidBST(root, pre, flag);
}


//����2���������
bool isValidBST(TreeNode* root) {
    if (!root)   return 1;
    int pre = 0;
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
            if (temp->left) s.push(temp->left);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            if (flag == 0)
            {
                pre = temp->val;
                flag = 1;
            }
            else
            {
                if (pre >= temp->val)    return 0;
                else    pre = temp->val;
            }
        }
    }

    return 1;
}
