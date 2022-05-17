#pragma once
#include<vector>
#include"二叉树.h"
using namespace std;
//力扣337
//题目：打家劫舍III_二叉树小区
//题目描述：这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
//          同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//          给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

//总体思路：后序遍历+dp
//方法1：树形dp，使用临时变量传递dp过的信息
//信息类型Money
struct Money {
    int mNo = 0;//mYes代表不偷取当前，可得到的最大值
    int mYes = 0;//mYes代表偷取当前，可得到的最大值
};
//遍历函数
Money posRob(TreeNode* root)
{
    if (!root)   return Money();

    Money mL = posRob(root->left);
    Money mR = posRob(root->right);
    Money m;
    m.mNo = max(mL.mYes, mL.mNo) + max(mR.mYes, mR.mNo);//不偷当前，左右看dp
    m.mYes = root->val + mL.mNo + mR.mNo;//偷取当前，不偷左右

    return m;
}
//主函数
int rob(TreeNode* root) {
    Money m = posRob(root);
    return max(m.mYes, m.mNo);
}

////方法2：dp + hashmap，使用hashmap存储dp过的信息
////遍历函数
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
////主函数
//int rob(TreeNode* root) {
//    unordered_map<TreeNode*, int> map;
//    map[(TreeNode*)nullptr] = 0;
//    posRob(root, map);
//    return map[root];
//}