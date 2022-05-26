#pragma once
#include"二叉树.h"
//力扣513
//题目：找树左下角的值
//题目描述：给定一个二叉树的 根节点 root，请找出该二叉树的最底层的最左边的节点的值。假设二叉树中至少有一个节点。


//方法1：先序递归（迭代也可以，不想写代码了）
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

//方法2：层序遍历
int findBottomLeftValue(TreeNode* root) {
    if (!root)   return 0;

    queue<TreeNode*> q;
    q.push(root);

    TreeNode* ret = NULL;

    while (!q.empty())
    {
        int count = q.size();
        ret = q.front();
        while (count--)
        {
            TreeNode* temp = q.front();
            q.pop();

            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    return ret->val;
}