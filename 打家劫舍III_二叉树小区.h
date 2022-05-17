#pragma once
#include<vector>
#include"������.h"
using namespace std;
//����337
//��Ŀ����ҽ���III_������С��
//��Ŀ����������ط����еķ��ݶ� Χ��һȦ ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�
//          ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ����� ��
//          ����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ �ڲ���������װ�õ������ �������ܹ�͵�Ե�����߽�

//����˼·���������+dp
//����1������dp��ʹ����ʱ��������dp������Ϣ
//��Ϣ����Money
struct Money {
    int mNo = 0;//mYes����͵ȡ��ǰ���ɵõ������ֵ
    int mYes = 0;//mYes����͵ȡ��ǰ���ɵõ������ֵ
};
//��������
Money posRob(TreeNode* root)
{
    if (!root)   return Money();

    Money mL = posRob(root->left);
    Money mR = posRob(root->right);
    Money m;
    m.mNo = max(mL.mYes, mL.mNo) + max(mR.mYes, mR.mNo);//��͵��ǰ�����ҿ�dp
    m.mYes = root->val + mL.mNo + mR.mNo;//͵ȡ��ǰ����͵����

    return m;
}
//������
int rob(TreeNode* root) {
    Money m = posRob(root);
    return max(m.mYes, m.mNo);
}

////����2��dp + hashmap��ʹ��hashmap�洢dp������Ϣ
////��������
//void posRob(TreeNode* root, unordered_map<TreeNode*, int>& map)
//{
//    if (!root)   return;
//
//    posRob(root->left, map);
//    posRob(root->right, map);
//
//    int mYes = root->val
//        + (root->left ? map[root->left->left] + map[root->left->right] : 0)
//        + (root->right ? map[root->right->left] + map[root->right->right] : 0);
//
//    int mNo = map[root->left] + map[root->right];
//
//    map[root] = max(mYes, mNo);
//}
////������
//int rob(TreeNode* root) {
//    unordered_map<TreeNode*, int> map;
//    map[(TreeNode*)nullptr] = 0;
//    posRob(root, map);
//    return map[root];
//}