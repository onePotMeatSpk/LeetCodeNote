#pragma once
#include"������.h"
//����235
//��Ŀ�������������������������
//��Ŀ����������һ������������, �ҵ�����������ָ���ڵ������������ȡ�

//��ͨ����������������ʹ��������������л��ݣ�Ч�ʺܵ�
//BST����������С�ڸ����������Դ��ڸ����ʶ����ö��ַ�
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root)
    {
        //rootֵ��������p��qֵ���м䣬��root��Ϊ�����������
        if (root->val >= p->val && root->val <= q->val)  return root;
        if (root->val <= p->val && root->val >= q->val)  return root;

        //rootֵ��������p��qֵ��һ�ߣ�����Ҫ����һ�߱���
        if (root->val < p->val && root->val < q->val) {
            root = root->right;
            continue;
        }
        if (root->val > p->val && root->val > q->val) {
            root = root->left;
            continue;
        }
    }

    return NULL;
}