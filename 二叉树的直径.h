#pragma once
#include"������.h"
//��Ŀ����������ֱ��
//��Ŀ����������һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ������·�����ܴ���Ҳ���ܲ���������㡣


//diameter���ֱ��
//����ֵΪroot�������
int diameterOfBinaryTreeCore(TreeNode* root, int& diameter)
{
    if (!root)  return 0;

    int leftDepth = diameterOfBinaryTreeCore(root->left, diameter);
    int rightDepth = diameterOfBinaryTreeCore(root->right, diameter);

    diameter = max(leftDepth + rightDepth, diameter);//���������ֱ��ʱ���滻

    return max(leftDepth, rightDepth) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    diameterOfBinaryTreeCore(root, diameter);
    return diameter;
}