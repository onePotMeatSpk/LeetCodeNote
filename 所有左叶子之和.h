#pragma once
#include"������.h"
//��Ŀ��������Ҷ��֮��
//��Ŀ�����������������ĸ��ڵ� root ������������Ҷ��֮�͡�

//��������������ǰ�������
//rootΪҪ����������
//flagIsLeft��־�������Ƿ�Ϊ����������Ϊtrue������Ϊfalse
//����root��������Ҷ�ӵĺ�
int sumOfLeftLeavesCore(TreeNode* root, bool flagIsLeft) {
    //³��
    if (!root)   return 0;

    //��Ҷ�ӽڵ㣬�����ж��ǲ�����Ҷ��
    if (!root->left && !root->right) return flagIsLeft ? root->val : 0;

    //����Ҷ�ӽڵ㣬��ôroot����Ҷ��֮�;�ֻȡ����������
    int count = 0;
    count += root->left ? sumOfLeftLeavesCore(root->left, 1) : 0;
    count += root->right ? sumOfLeftLeavesCore(root->right, 0) : 0;
    return  count;
}

int sumOfLeftLeaves(TreeNode* root) {
    return sumOfLeftLeavesCore(root, 0);
}