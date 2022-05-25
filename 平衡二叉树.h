#pragma once
#include"������.h"
using namespace std;

//����110
//��Ŀ��ƽ�������
//��Ŀ����������һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

//����1������ݹ�
//�Զ��巵��ֵ����Res
struct Res
{
    bool isBal = 1;//�����Ƿ�ƽ��
    int depth = 0;//�������
};

//��������dfs
Res dfsIsBalanced(TreeNode* root) {
    if (!root)   return Res();

    Res l = dfsIsBalanced(root->left);
    Res r = dfsIsBalanced(root->right);

    Res now;
    //�����Ƿ�ƽ�⣬ȡ����1�����������Ƿ�ƽ��2�����������߶Ȳ�
    now.isBal = l.isBal && r.isBal && abs(l.depth - r.depth) <= 1;
    //�����߶ȣ�ȡ�������������и���
    now.depth = max(l.depth, r.depth) + 1;

    return now;
}

//������������dfs
bool isBalanced(TreeNode* root) {
    Res now = dfsIsBalanced(root);
    return now.isBal;
}

//����2������
//����������ڵ�߶ȣ����������ǰ������Ҳ�ɣ�
int heightOfRoot(TreeNode* root)
{
    if (!root)   return 0;

    stack<TreeNode*> s;
    int depth = 0, height = 0;//depth��ʾ����ջ�������ȣ�height��ʾջ��������������ȣ��ڵ�ĸ߶ȣ������Խڵ�Ϊ�������������ȣ�
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

//���������ж�ƽ�⣬ǰ�������Ҳ���Ժ���ֻ������Ҫʹ��map<TreeNode*, int>�����ӽڵ㼰��߶ȵĹ�ϵ���Ա㸸�ڵ��ѯ��
//ǰ������㷨���жϸ������������߶Ȳ��Ƿ�С��2��
//                  �ǣ������������ֱ��ж����������Ƿ�ƽ��
//                  ��˵����ƽ�⣬ֱ�ӷ���
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