#pragma once
#include"������.h"
using namespace std;

//����124
//��Ŀ�����������·����
//��Ŀ������·�� ������Ϊһ������������ڵ�������ظ��ڵ�-�ӽڵ����ӣ��ﵽ����ڵ�����С�ͬһ���ڵ���һ��·�������� �������һ�� ����·�� ���ٰ���һ�� �ڵ㣬�Ҳ�һ���������ڵ㡣
//			·���� ��·���и��ڵ�ֵ���ܺ͡�
//			����һ���������ĸ��ڵ� root �������� ���·���� ��

//˼·�����ƶ�������ֱ��
//
struct Res {
    int sumForIn;//����·����ĳ���ڵ����·����
    int sumForOut;//����·����ĳ���ڵģ��յ�Ϊ���ڵ��·����·���ͣ������������������̽��������·��
    Res() : sumForIn(-9999), sumForOut(-9999) {};//-9999������Ϊ����124�нڵ���СΪ-1000
};

struct Res dfsMaxPathSum(TreeNode* root) {
    Res res;
    //����NULL���ݹ���ֹ
    if (!root)   return res;
    //�ռ�����������Ϣ
    Res resL = dfsMaxPathSum(root->left);
    Res resR = dfsMaxPathSum(root->right);

    //��Ϣ����
    // 
    //��������·���������ֿ��ܣ������������������Ǹ��ڵ㣬ȡ��������߼���
    //��������������п�����������������������ȡ�������ֵ����
    //����Ǹ��ڵ㣺ֱ��ȡ���ڵ�ֵ����
    res.sumForOut = max(max(resL.sumForOut, resR.sumForOut), 0) + root->val;

    //��������·���������ֿ��ܣ�������������root��ȡ��������߼���
    //����root�����ֿ��ܣ�����ҡ���������ҡ�����ȡ�������ֵ���ɣ��������Ҷ���ȡ��������������·��
    //������root��ȡ��������������·���е������
    res.sumForIn = max(max(max(resL.sumForIn, resR.sumForIn), max(resL.sumForOut, resR.sumForOut) + root->val),
        max(resL.sumForOut + resR.sumForOut + root->val, root->val));
    return res;
}

int maxPathSum(TreeNode* root) {
    if (!root)   return 0;
    Res res = dfsMaxPathSum(root);
    return res.sumForIn;
}
