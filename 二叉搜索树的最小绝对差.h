#pragma once
#include"������.h"
//��Ŀ����������������С���Բ�
// ��Ŀ����������һ�������������ĸ��ڵ� root ������ ������������ͬ�ڵ�ֵ֮�����С��ֵ ����ֵ��һ������������ֵ������ֵ
//			֮��ľ���ֵ��

//˼·������������������������Ϊ˳�����֣���ô�������ڵ�ľ��Բ������С�ģ��������Ҿ�����

void getMinimumDifferenceCore(TreeNode* root, TreeNode*& prev, int& diff)
{
    if (!root)   return;
    getMinimumDifferenceCore(root->left, prev, diff);
    int ab = prev ? abs(root->val - prev->val) : -1;
    diff = ab == -1 ? -1 : (diff == -1 ? ab : (diff > ab ? ab : diff));
    prev = root;
    getMinimumDifferenceCore(root->right, prev, diff);
}
int getMinimumDifference(TreeNode* root) {
    TreeNode* prev = NULL;
    int diff;
    getMinimumDifferenceCore(root, prev, diff);
    return diff;
}