#pragma once
#include"二叉树.h"
//力扣543
//题目：二叉树的直径
//题目描述：给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。



struct res {
    int depth;//某树深度
    int diameter;//某树直径
    res() : depth(0), diameter(0) {};
};

//dfs函数
struct res dfsDiameterOfBinaryTree(TreeNode* root) {
    //递归终止
    res r;
    if (!root)   return r;
    //收集左右信息
    res rL = dfsDiameterOfBinaryTree(root->left);
    res rR = dfsDiameterOfBinaryTree(root->right);
    //信息汇总
    r.depth = max(rL.depth, rR.depth) + 1;//本树深度，自然是左右子树最深者加一
    //本树直径，有两种可能：经过、不经过root，取两者最大者即可
    //经过root：那最长路径自然是，左子树深度+左右子树深度
    //不经过root：那说明最长直径存在于某一子树中，就是左子树或者右子树的直径，取两者最大者即可
    r.diameter = max(max(rL.diameter, rR.diameter), rL.depth + rR.depth);
    return r;
}

//主函数
int diameterOfBinaryTree(TreeNode* root) {
    res r = dfsDiameterOfBinaryTree(root);
    return r.diameter;
}