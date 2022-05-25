#pragma once
#include"������.h"
#include<vector>
#include<string>
using namespace std;

//����257
//��Ŀ��������������·��
//��Ŀ����������һ���������ĸ��ڵ� root ���� ����˳�� ���������дӸ��ڵ㵽Ҷ�ӽڵ��·����

//����1���ݹ����
//�����������ݷ�
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

//������
vector<string> binaryTreePaths(TreeNode* root) {
    vector<TreeNode*> v;
    vector<string> vS;
    dfsBinaryTreePaths(root, v, vS);
    return vS;
}


//����2����������
//�������
vector<string> binaryTreePaths(TreeNode* root) {
    vector<TreeNode*> v;//v����·�����ں������Ľڵ�
    vector<string> vS;//vS��������·��
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
            //��ջʱ�����ڵ����·���������ֳ�
            v.push_back(temp);

            if (temp->right) s.push(temp->right);
            if (temp->left)  s.push(temp->left);
        }
        else
        {
            s.pop();
            temp = s.top();
            s.pop();

            //��ջʱ���ж��Ƿ���Ҷ�ӽڵ㣬������
            if (!temp->left && !temp->right)
            {
                string str;
                for (int i = 0; i < v.size() - 1; i++)
                    str += to_string(v[i]->val) + "->";
                str += to_string(temp->val);
                vS.push_back(str);
            }
            //��ջʱ���ָ��ֳ�
            v.pop_back();
        }
    }

    return vS;
}
