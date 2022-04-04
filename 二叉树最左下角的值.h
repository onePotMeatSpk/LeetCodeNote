#pragma once
#include"二叉树.h"
//题目：二叉树最左下角的值
//题目描述：给定一个二叉树的 根节点 root，请找出该二叉树的最底层的最左边的节点的值。假设二叉树中至少有一个节点。


//辅助函数（基于先序遍历）
//maxDepth记录当前遍历到的最深节点的深度
//valTemp记录maxDepth对应节点的值
//root表示下一个要遍历的树
//depth表示往下一层的深度
void findBottomLeftValueCore(int& maxDepth, int& valTemp, TreeNode*& root, int depth)
{
    if (!root)   return;

    //找到一个叶子结点
    if (!root->left && !root->right)
        if (maxDepth < depth)//比maxDepth更深的话，就更新最深深度和值，否则不更新（深度和maxDepth一样也不更新，因为在先
                             //序遍历中，左边的节点肯定更早被遍历到）
        {
            maxDepth = depth;
            valTemp = root->val;
        }

    findBottomLeftValueCore(maxDepth, valTemp, root->left, depth + 1);
    findBottomLeftValueCore(maxDepth, valTemp, root->right, depth + 1);
}

int findBottomLeftValue(TreeNode* root)
{
    int maxDepth = -1;
    int valTemp = 0;
    findBottomLeftValueCore(maxDepth, valTemp, root, 0);
    return valTemp;
}