#pragma once
#include"������.h"
//��Ŀ�����������ڵ���������
//��Ŀ����������һ��������, �ҵ�����������ָ���ڵ������������ȡ��ٶȰٿ�������������ȵĶ���Ϊ���������и��� T �������ڵ� p��q������������ȱ�ʾΪһ���ڵ� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

//��ȷ�����ڵ㶼������ʱ���ſ���ʹ�ø÷���
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root)   return NULL;
    if ((root == p) || (root == q))  return root;
    TreeNode* resLeft = lowestCommonAncestor1(root->left, p, q);
    TreeNode* resRight = lowestCommonAncestor1(root->right, p, q);
    if (resLeft && resRight) return root;
    if (resLeft) return resLeft;
    if (resRight)    return resRight;
    return NULL;
}


//�÷�ʽ�����ڲ�ȷ�����ڵ㶼������
int lowestCommonAncestor2Core(TreeNode* root, TreeNode*& p, TreeNode*& q, TreeNode*& find)
{
    if (!root)   return 0;
    int l, r, s;
    if ((l = lowestCommonAncestor2Core(root->left, p, q, find)) == 3)   return 3;
    if ((r = lowestCommonAncestor2Core(root->right, p, q, find)) == 3)   return 3;

    s = l + r;

    if (s == 3)
    {
        find = root;
        return 3;
    }

    if (s)
    {
        if ((root == p) || (root == q))
        {
            find = root;
            return 3;
        }
        return s;
    }

    if (root == p)   return 1;
    if (root == q)   return 2;
    return 0;
}
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* find = NULL;
    if (lowestCommonAncestor2Core(root, p, q, find) == 3) return find;
    return NULL;
}
