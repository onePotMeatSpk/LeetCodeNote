#pragma once
#include"二叉树.h"
//力扣236
//题目：二叉树的最近公共祖先
//题目描述：给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。


//方法1：代码量多，但容易理解
//自定义返回类型
struct Ret {
    TreeNode* ancp = NULL;//p的祖先
    TreeNode* ancq = NULL;//q的祖先
};

//后序递归函数
Ret dfslowestCommonAncestor(TreeNode* root, TreeNode*& p, TreeNode*& q) {
    //递归终止
    if (!root)   return Ret();

    //遍历左右子树
    Ret retL = dfslowestCommonAncestor(root->left, p, q);
    if (retL.ancp && retL.ancq)  return retL;//如果p、q均在左子树中，直接返回即可
    Ret retR = dfslowestCommonAncestor(root->right, p, q);
    if (retR.ancp && retR.ancq)  return retR;//如果p、q均在左子树中，直接返回即可

    //处理本节点
    Ret retM;
    retM.ancp = root == p ? root : retL.ancp ? retL.ancp : retR.ancp;//本节点若是p，则retM.ancp = root；否则到左右子树返回值中，寻找p的祖先
    retM.ancq = root == q ? root : retL.ancq ? retL.ancq : retR.ancq;//q，同p处理方式
    if (retM.ancp && retM.ancq && retM.ancp != retM.ancq)//p、q祖先均已找到，但却并非同一节点，那本节点就是他们最近公共祖先
        retM.ancp = retM.ancq = root;

    return retM;
}

//主函数
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    Ret ret = dfslowestCommonAncestor(root, p, q);
    return ret.ancp;
}


//方法2：代码量少，但是不易理解
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