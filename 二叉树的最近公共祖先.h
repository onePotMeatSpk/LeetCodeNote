#pragma once
#include"������.h"
//����236
//��Ŀ���������������������
//��Ŀ����������һ��������, �ҵ�����������ָ���ڵ������������ȡ�


//����1���������࣬���������
//�Զ��巵������
struct Ret {
    TreeNode* ancp = NULL;//p������
    TreeNode* ancq = NULL;//q������
};

//����ݹ麯��
Ret dfslowestCommonAncestor(TreeNode* root, TreeNode*& p, TreeNode*& q) {
    //�ݹ���ֹ
    if (!root)   return Ret();

    //������������
    Ret retL = dfslowestCommonAncestor(root->left, p, q);
    if (retL.ancp && retL.ancq)  return retL;//���p��q�����������У�ֱ�ӷ��ؼ���
    Ret retR = dfslowestCommonAncestor(root->right, p, q);
    if (retR.ancp && retR.ancq)  return retR;//���p��q�����������У�ֱ�ӷ��ؼ���

    //�����ڵ�
    Ret retM;
    retM.ancp = root == p ? root : retL.ancp ? retL.ancp : retR.ancp;//���ڵ�����p����retM.ancp = root������������������ֵ�У�Ѱ��p������
    retM.ancq = root == q ? root : retL.ancq ? retL.ancq : retR.ancq;//q��ͬp����ʽ
    if (retM.ancp && retM.ancq && retM.ancp != retM.ancq)//p��q���Ⱦ����ҵ�����ȴ����ͬһ�ڵ㣬�Ǳ��ڵ�������������������
        retM.ancp = retM.ancq = root;

    return retM;
}

//������
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    Ret ret = dfslowestCommonAncestor(root, p, q);
    return ret.ancp;
}


//����2���������٣����ǲ������
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root)   return NULL;

    TreeNode* retL = lowestCommonAncestor(root->left, p, q);
    TreeNode* retR = lowestCommonAncestor(root->right, p, q);

    if (retL && retR)  return root;
    if (root == p || root == q)  return root;
    else if (retL)    return retL;
    else if (retR)   return retR;

    return NULL;
}