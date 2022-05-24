#pragma once
#include"二叉树.h"
using namespace std;

//力扣110
//题目：平衡二叉树
//题目描述：给定一个二叉树，判断它是否是高度平衡的二叉树。

//自定义返回值类型Res
struct Res
{
    bool isBal = 1;//该树是否平衡
    int depth = 0;//该树深度
};

Res dfsIsBalanced(TreeNode* root) {
    if (!root)   return Res();

    Res l = dfsIsBalanced(root->left);
    Res r = dfsIsBalanced(root->right);

    Res now;
    //该树是否平衡，取决于1、左右子树是否平衡2、左右子树高度差
    now.isBal = l.isBal && r.isBal && abs(l.depth - r.depth) <= 1;
    //该树高度，取决于左右子树中高者
    now.depth = max(l.depth, r.depth) + 1;

    return now;
}

bool isBalanced(TreeNode* root) {
    Res now = dfsIsBalanced(root);
    return now.isBal;
}