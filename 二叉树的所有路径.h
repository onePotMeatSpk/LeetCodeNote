#pragma once
#include"二叉树.h"
#include<vector>
#include<string>
using namespace std;

//力扣257
//题目：二叉树的所有路径
//题目描述：给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

//方法1：递归回溯
//辅函数：回溯法
void dfsBinaryTreePaths(TreeNode* root, vector<TreeNode*>& v, vector<string>& vS)
{
    if (!root)   return;
    if (!root->left && !root->right)
    {
        string s;
        for (int i = 0; i < v.size(); i++)
            s += to_string(v[i]->val) + "->";
        s += to_string(root->val);
        vS.push_back(s);
        return;
    }

    v.push_back(root);
    dfsBinaryTreePaths(root->left, v, vS);
    dfsBinaryTreePaths(root->right, v, vS);
    v.pop_back();
}

//主函数
vector<string> binaryTreePaths(TreeNode* root) {
    vector<TreeNode*> v;
    vector<string> vS;
    dfsBinaryTreePaths(root, v, vS);
    return vS;
}


//方法2：迭代回溯
//后序遍历
vector<string> binaryTreePaths(TreeNode* root) {
    vector<TreeNode*> v;//v代表路径，内含经过的节点
    vector<string> vS;//vS代表所有路径
    if (!root)   return vS;

    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode* temp = s.top();
        if (temp)
        {
            s.pop();
            s.push(temp);
            s.push(NULL);
            //入栈时，将节点加入路径，布置现场
            v.push_back(temp);

            if (temp->right) s.push(temp->right);
            if (temp->left)  s.push(temp->left);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            //出栈时，判断是否是叶子节点，并操作
            if (!temp->left && !temp->right)
            {
                string str;
                for (int i = 0; i < v.size() - 1; i++)
                    str += to_string(v[i]->val) + "->";
                str += to_string(temp->val);
                vS.push_back(str);
            }
            //出栈时，恢复现场
            v.pop_back();
        }
    }

    return vS;
}
