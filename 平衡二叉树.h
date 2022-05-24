#pragma once
#include"������.h"
using namespace std;

//����110
//��Ŀ��ƽ�������
//��Ŀ����������һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

//�Զ��巵��ֵ����Res
struct Res
{
    bool isBal = 1;//�����Ƿ�ƽ��
    int depth = 0;//�������
};

Res dfsIsBalanced(TreeNode* root) {
    if (!root)   return Res();

    Res l = dfsIsBalanced(root->left);
    Res r = dfsIsBalanced(root->right);

    Res now;
    //�����Ƿ�ƽ�⣬ȡ����1�����������Ƿ�ƽ��2�����������߶Ȳ�
    now.isBal = l.isBal && r.isBal && abs(l.depth - r.depth) <= 1;
    //�����߶ȣ�ȡ�������������и���
    now.depth = max(l.depth, r.depth) + 1;

    return now;
}

bool isBalanced(TreeNode* root) {
    Res now = dfsIsBalanced(root);
    return now.isBal;
}