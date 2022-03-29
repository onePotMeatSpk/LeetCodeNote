#pragma once
#include"������.h"

//��Ŀ���Ƿ�Գƶ�����
//��Ŀ����������һ���������ĸ��ڵ� root �� ������Ƿ���Գ�

bool isSymmetricCore(TreeNode* root0, TreeNode* root1)
{
    //���жϵ�ǰ�����ڵ��Ƿ����
    if ((!root0) && (!root1))    return 1;
    if ((!root0) || (!root1))  return 0;
    if (root0->val != root1->val)    return 0;

    //���ж��������ڵ�Ϊ�������������Ƿ�Գ�
    return isSymmetricCore(root0->left, root1->right) && isSymmetricCore(root0->right, root1->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root)   return 1;
    return isSymmetricCore(root->left, root->right);
}