#pragma once
#include"二叉树.h"
//题目：恢复二叉搜索树
// 题目描述：给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树。

//解题思路：中序遍历情况下，正常搜索二叉树各节点值应该为单调递增。画图可以发现，如果当前节点小于前节点，则说明前节点或当
//前节点至少一个异常。题目中说仅有两个交换过，那么在中序遍历中，遇到的第一个大于后续节点的节点就是第一个异常节点，遇到
//的最后一个小于前节点的当前节点就是第二个异常节点

//辅助函数：中序遍历从而得到异常节点
void recoverTreeCore(TreeNode* root, TreeNode*& mistake1, TreeNode*& mistake2, TreeNode*& pre) {
    if (!root)   return;
    //遍历左子树
    //直接把当前树的pre传给左子树是因为，画图可理解，当前树的最左端的子孙的前节点就是当前树的前节点
    recoverTreeCore(root->left, mistake1, mistake2, pre);
    //如果前节点为NULL，说明当前节点在树的最左端那一枝，自然无前节点
    //如果前节点不为NULL，说明已经遍历了最左端的第一个节点
    if (pre)
    {
        //当前节点值小于前节点值，异常了
        if (root->val < pre->val)
        {
            //异常节点都还没有确定，就先把这一对填上，mistake1肯定是异常节点中大的那个，因为是遇到的第一个异常节点
            if (!mistake1)
            {
                mistake1 = pre;
                mistake2 = root;
            }
            //如果后续遇到了比mistake2还小的节点，那就更换mistake2，直到遇到最后一个异常节点
            else if (root->val < mistake2->val)
                mistake2 = root;
        }
    }
    pre = root;
    //遍历右子树
    recoverTreeCore(root->right, mistake1, mistake2, pre);
}
void recoverTree(TreeNode* root) {
    TreeNode* mistake1 = NULL;
    TreeNode* mistake2 = NULL;
    TreeNode* pre = NULL;

    recoverTreeCore(root, mistake1, mistake2, pre);
    //交换两节点的值
    int temp = mistake1->val;
    mistake1->val = mistake2->val;
    mistake2->val = temp;
}