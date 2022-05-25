#pragma once
#include"二叉树.h"
using namespace std;

//力扣110
//题目：平衡二叉树
//题目描述：给定一个二叉树，判断它是否是高度平衡的二叉树。

//方法1：后序递归
//自定义返回值类型Res
struct Res
{
    bool isBal = 1;//该树是否平衡
    int depth = 0;//该树深度
};

//辅函数：dfs
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

//主函数：调用dfs
bool isBalanced(TreeNode* root) {
    Res now = dfsIsBalanced(root);
    return now.isBal;
}

//方法2：迭代
//辅函数：求节点高度，后序迭代（前序、中序也可）
int heightOfRoot(TreeNode* root)
{
    if (!root)   return 0;

    stack<TreeNode*> s;
    int depth = 0, height = 0;//depth表示现在栈到达的深度，height表示栈曾经到达的最大深度（节点的高度，就是以节点为根的树的最大深度）
    s.push(root);

    while (!s.empty())
    {
        TreeNode* temp = s.top();

        if (temp)
        {
            s.pop();
            s.push(temp);
            s.push(NULL);
            depth++;

            if (temp->left)  s.push(temp->left);
            if (temp->right) s.push(temp->right);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();
            depth--;
        }

        height = max(height, depth);
    }

    return height;
}

//主函数：判断平衡，前序迭代（也可以后序，只不过需要使用map<TreeNode*, int>保存子节点及其高度的关系，以便父节点查询）
//前序迭代算法：判断根的左右子树高度差是否小于2，
//                  是：继续迭代，分别判断左右子树是否平衡
//                  否：说明不平衡，直接返回
bool isBalanced(TreeNode* root)
{
    if (!root)   return 1;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode* temp = s.top();
        
        if (temp)
        {
            s.pop();
            
            if (temp->left)  s.push(temp->left);
            if (temp->right) s.push(temp->right);

            s.push(temp);
            s.push(NULL);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            int heightL = heightOfRoot(temp->left);
            int heightR = heightOfRoot(temp->right);
            if (abs(heightL - heightR) > 1)    return 0;
        }
    }

    return 1;
}