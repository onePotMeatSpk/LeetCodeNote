#pragma once
#include"������.h"
using namespace std;

//����222
//��Ŀ����ȫ�������Ľڵ����
//��Ŀ����������һ�� ��ȫ������ �ĸ��ڵ� root ����������Ľڵ������
 
//!!!���ף���������ͳ�ƽڵ���һ��ʱ�临�Ӷ�Ϊ O(n) �ļ򵥽����������������һ��������㷨��

//���������Ľڵ������2^depth - 1����ȫ�������б�Ȼ�������������ʶ�����������Щ����������������ʱ�临�Ӷ�
//��ÿ���ڵ㴦���ж�����Ϊ�������Ƿ����������������������������ô�����ұߵĸ߶�һ�����
//�����Ƿ�������������ѡ�����ڵ������ķ�����
//      �ǣ�2^depth - 1
//      ���������ڵ����� + �������ڵ����� + 1
int countNodes(TreeNode* root) {
    if (!root)   return 0;

    //�������ұߵĸ߶�
    int depthL = 0, depthR = 0;
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    while (l)
    {
        depthL++;
        l = l->left;
    }
    while (r)
    {
        depthR++;
        r = r->right;
    }

    //����ڵ�����
    //������ұ߸߶���ȣ�������������������ʹ�ù�ʽ
    if (depthL == depthR)    return pow(2, depthL + 1) - 1;
    //�����������������Ҫ����������ӣ��ټ�1
    else    return countNodes(root->left) + countNodes(root->right) + 1;
}