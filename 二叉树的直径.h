#pragma once
#include"������.h"
//����543
//��Ŀ����������ֱ��
//��Ŀ����������һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ������·�����ܴ���Ҳ���ܲ���������㡣



struct res {
    int depth;//ĳ�����
    int diameter;//ĳ��ֱ��
    res() : depth(0), diameter(0) {};
};

//dfs����
struct res dfsDiameterOfBinaryTree(TreeNode* root) {
    //�ݹ���ֹ
    res r;
    if (!root)   return r;
    //�ռ�������Ϣ
    res rL = dfsDiameterOfBinaryTree(root->left);
    res rR = dfsDiameterOfBinaryTree(root->right);
    //��Ϣ����
    r.depth = max(rL.depth, rR.depth) + 1;//������ȣ���Ȼ���������������߼�һ
    //����ֱ���������ֿ��ܣ�������������root��ȡ��������߼���
    //����root�����·����Ȼ�ǣ����������+�����������
    //������root����˵���ֱ��������ĳһ�����У�����������������������ֱ����ȡ��������߼���
    r.diameter = max(max(rL.diameter, rR.diameter), rL.depth + rR.depth);
    return r;
}

//������
int diameterOfBinaryTree(TreeNode* root) {
    res r = dfsDiameterOfBinaryTree(root);
    return r.diameter;
}