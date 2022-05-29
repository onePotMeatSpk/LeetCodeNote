#pragma once
#include"二叉树.h"
#include<stack>
using namespace std;

//力扣98
//题目：验证二叉搜索树
//题目描述：给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
			//有效 二叉搜索树定义如下：
			//
			//节点的左子树只包含 小于 当前节点的数。
			//节点的右子树只包含 大于 当前节点的数。
			//所有左子树和右子树自身必须也是二叉搜索树。


//思路：中序遍历，如果该处值小于等于前节点值，则说明不是BST

//方法1：中序递归
//pre：前节点的值
//flag：表示前方是否有节点，在遍历最左下方节点时置1，此后的节点才可以开始与pre比较
bool dfsIsValidBST(TreeNode* root, int& pre, bool& flag) {
    if (!root)   return 1;

    if (!dfsIsValidBST(root->left, pre, flag))    return 0;

    if (flag == 0)
    {
        pre = root->val;
        flag = 1;
    }
    else
    {
        if (pre >= root->val)    return 0;//中序遍历，如果该处值小于等于前节点值，则说明不是BST
        else pre = root->val;
    }

    if (!dfsIsValidBST(root->right, pre, flag))    return 0;
    return 1;
}


bool isValidBST(TreeNode* root) {
    int pre = 0;
    bool flag = 0;
    return dfsIsValidBST(root, pre, flag);
}


//方法2：中序迭代
bool isValidBST(TreeNode* root) {
    if (!root)   return 1;
    int pre = 0;
    bool flag = 0;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.pop();

            if (temp->right) s.push(temp->right);
            s.push(temp);
            s.push(NULL);
            if (temp->left) s.push(temp->left);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            if (flag == 0)
            {
                pre = temp->val;
                flag = 1;
            }
            else
            {
                if (pre >= temp->val)    return 0;
                else    pre = temp->val;
            }
        }
    }

    return 1;
}
