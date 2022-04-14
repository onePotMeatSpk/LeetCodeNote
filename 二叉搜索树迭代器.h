#pragma once
#include<stack>
#include"二叉树.h"
using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        nodeRoot = root;
    }

    int next() {
        //迭代器还是初始状态
        if (s.empty() && nodeRoot)
        {
            TreeNode* temp = nodeRoot;
            nodeRoot = NULL;
            while (temp)
            {
                s.push(temp);
                temp = temp->left;
            }
        }
        //迭代器已非初始状态
        //当前节点没有右子树，则next为其父节点
        else if (s.top()->right == NULL)
            s.pop();
        //当前节点有右子树，则next为其右子树的最左侧节点
        else
        {
            TreeNode* temp = s.top()->right;
            s.pop();
            s.push(temp);
            temp = temp->left;
            while (temp)
            {
                s.push(temp);
                temp = temp->left;
            }
        }

        return s.top()->val;
    }

    bool hasNext() {
        //若当前迭代器还是初始状态
        if (nodeRoot)    return true;
        //若当前节点有右子树
        if (s.top()->right)  return true;
        //若当前节点有父节点
        if (s.size() >= 2) return true;

        return false;

    }

private:
    stack<TreeNode*> s;
    TreeNode* nodeRoot;
};